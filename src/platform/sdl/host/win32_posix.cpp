// POSIX implementations of the Win32 host functions (win32_posix.h; docs/native-mac.md "Host side"). The shapes
// (arguments, results, error codes) are the public Win32 ones the shims already use against kernel32 under Wine;
// nothing here comes from Microsoft code.
#if !defined(_WIN32)
#include "win32_posix.h"

#include <errno.h>
#include <fcntl.h>
#include <pthread.h>
#include <sched.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/statvfs.h>
#include <sys/time.h>
#include <time.h>
#include <unistd.h>

#include <atomic>

// ---------------------------------------------------------------------------------------------------------------
// The last error and the thread ids
static thread_local hulk_u32 t_last_error;
static thread_local hulk_u32 t_tid;
static std::atomic<hulk_u32> g_next_tid{1};

extern "C" hulk_u32 HULK_HOST_STDCALL hulk_host_GetLastError(void) { return t_last_error; }
extern "C" void HULK_HOST_STDCALL hulk_host_SetLastError(hulk_u32 code) { t_last_error = code; }

static hulk_u32 own_tid() {
    if (!t_tid)
        t_tid = g_next_tid.fetch_add(4);   // (Win32 thread ids are multiples of 4)
    return t_tid;
}
extern "C" hulk_u32 HULK_HOST_STDCALL hulk_host_GetCurrentThreadId(void) { return own_tid(); }

static hulk_u32 errno_to_win32(int e) {
    switch (e) {
    case ENOENT: return HULK_ERROR_FILE_NOT_FOUND;
    case ENOTDIR: return HULK_ERROR_PATH_NOT_FOUND;
    case EACCES: case EPERM: case EROFS: return HULK_ERROR_ACCESS_DENIED;
    case EEXIST: return HULK_ERROR_ALREADY_EXISTS;
    case ENOSPC: return HULK_ERROR_DISK_FULL;
    case ENOMEM: return HULK_ERROR_NOT_ENOUGH_MEMORY;
    case EBADF: return HULK_ERROR_INVALID_HANDLE;
    default: return HULK_ERROR_INVALID_PARAMETER;
    }
}

// ---------------------------------------------------------------------------------------------------------------
// Handles: one object kind each, a magic word to refuse what is not ours
enum Kind : unsigned { K_THREAD = 0x54485244u, K_SEMAPHORE = 0x53454d41u, K_EVENT = 0x45564e54u, K_FILE = 0x46494c45u };

struct HulkHostObject {
    unsigned kind;
    std::atomic<int> refs;            // the handle, plus the running thread for a thread object
    pthread_mutex_t mu;
    pthread_cond_t cv;
};

struct ThreadObj : HulkHostObject {
    pthread_t th;
    hulk_u32 tid;
    hulk_u32 (*start)(void*);
    void* param;
    int suspended;                    // CREATE_SUSPENDED: the thread waits on cv until ResumeThread
    int done;
    hulk_u32 exit_code;
};

struct SemaphoreObj : HulkHostObject {
    int count, maximum;
};

struct EventObj : HulkHostObject {
    int signaled, manual;
};

struct FileObj : HulkHostObject {
    int fd;
};

static void obj_init(HulkHostObject* o, unsigned kind, int refs) {
    o->kind = kind;
    o->refs.store(refs);
    pthread_mutex_init(&o->mu, 0);
    pthread_cond_init(&o->cv, 0);
}

static void obj_release(HulkHostObject* o) {
    if (o->refs.fetch_sub(1) != 1)
        return;
    pthread_cond_destroy(&o->cv);
    pthread_mutex_destroy(&o->mu);
    o->kind = 0;
    ::operator delete(o);   // (every object kind is trivially destructible)
}

template <class T> static T* as(void* h, unsigned kind) {
    if (!h || h == HULK_INVALID_HANDLE_VALUE)
        return 0;
    HulkHostObject* o = (HulkHostObject*)h;
    return o->kind == kind ? (T*)o : 0;
}

// waits on o->cv (o->mu held) until ready() or the timeout; 1 = ready
template <class F> static int wait_until(HulkHostObject* o, hulk_u32 ms, F ready) {
    if (ms == HULK_INFINITE) {
        while (!ready())
            pthread_cond_wait(&o->cv, &o->mu);
        return 1;
    }
    struct timeval now;
    gettimeofday(&now, 0);
    struct timespec until;
    long long ns = (long long)now.tv_usec * 1000 + (long long)(ms % 1000) * 1000000;
    until.tv_sec = now.tv_sec + ms / 1000 + (time_t)(ns / 1000000000);
    until.tv_nsec = (long)(ns % 1000000000);
    while (!ready())
        if (pthread_cond_timedwait(&o->cv, &o->mu, &until) == ETIMEDOUT)
            return ready();
    return 1;
}

// ---------------------------------------------------------------------------------------------------------------
// Threads
static thread_local struct ThreadObj* t_self;

static void* thread_main(void* arg) {
    ThreadObj* t = (ThreadObj*)arg;
    t_tid = t->tid;
    t_self = t;
    pthread_mutex_lock(&t->mu);
    while (t->suspended)
        pthread_cond_wait(&t->cv, &t->mu);
    pthread_mutex_unlock(&t->mu);
    hulk_u32 code = t->start(t->param);
    hulk_host_ExitThread(code);   // (does not return)
    return 0;
}

extern "C" void* HULK_HOST_STDCALL hulk_host_CreateThread(void* sa, hulk_u32 stack, void* start, void* param,
                                                         hulk_u32 flags, hulk_u32* tid) {
    (void)sa;
    ThreadObj* t = new ThreadObj;
    obj_init(t, K_THREAD, 2);
    t->tid = g_next_tid.fetch_add(4);
    t->start = (hulk_u32(*)(void*))start;
    t->param = param;
    t->suspended = (flags & HULK_CREATE_SUSPENDED) != 0;
    t->done = 0;
    t->exit_code = 0x103;   // STILL_ACTIVE
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    size_t sz = stack < 0x100000 ? 0x100000 : stack;   // (at least 1 MB: clang frames are bigger than the Xbox's)
    pthread_attr_setstacksize(&attr, (sz + 0xfff) & ~(size_t)0xfff);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
    int rc = pthread_create(&t->th, &attr, thread_main, t);
    pthread_attr_destroy(&attr);
    if (rc) {
        obj_release(t);
        obj_release(t);
        hulk_host_SetLastError(HULK_ERROR_NOT_ENOUGH_MEMORY);
        return 0;
    }
    if (tid)
        *tid = t->tid;
    return t;
}

extern "C" void HULK_HOST_STDCALL hulk_host_ExitThread(hulk_u32 code) {
    ThreadObj* t = t_self;
    if (!t) {
        // a thread we did not create (the main thread): there is no handle to signal
        pthread_exit(0);
    }
    pthread_mutex_lock(&t->mu);
    t->exit_code = code;
    t->done = 1;
    pthread_cond_broadcast(&t->cv);
    pthread_mutex_unlock(&t->mu);
    obj_release(t);
    pthread_exit(0);
}

extern "C" hulk_u32 HULK_HOST_STDCALL hulk_host_ResumeThread(void* h) {
    ThreadObj* t = as<ThreadObj>(h, K_THREAD);
    if (!t) {
        hulk_host_SetLastError(HULK_ERROR_INVALID_HANDLE);
        return 0xffffffffu;
    }
    pthread_mutex_lock(&t->mu);
    hulk_u32 prev = t->suspended ? 1 : 0;
    t->suspended = 0;
    pthread_cond_broadcast(&t->cv);
    pthread_mutex_unlock(&t->mu);
    return prev;
}

// Suspending a running thread from outside (the Wine build's hang watchdog) has no POSIX counterpart: refused.
extern "C" hulk_u32 HULK_HOST_STDCALL hulk_host_SuspendThread(void* h) {
    (void)h;
    hulk_host_SetLastError(HULK_ERROR_NOT_SUPPORTED);
    return 0xffffffffu;
}

extern "C" int HULK_HOST_STDCALL hulk_host_GetThreadContext(void* h, void* context) {
    (void)h; (void)context;
    hulk_host_SetLastError(HULK_ERROR_NOT_SUPPORTED);
    return 0;
}

extern "C" void* HULK_HOST_STDCALL hulk_host_OpenThread(hulk_u32 access, int inherit, hulk_u32 tid) {
    (void)access; (void)inherit; (void)tid;
    hulk_host_SetLastError(HULK_ERROR_NOT_SUPPORTED);
    return 0;
}

// Xbox / Win32 priorities -15..15; the host scheduler gets a hint only (a time-critical thread asks for the top of
// the default policy's range)
extern "C" int HULK_HOST_STDCALL hulk_host_SetThreadPriority(void* h, int priority) {
    ThreadObj* t = as<ThreadObj>(h, K_THREAD);
    if (!t)
        return 1;   // (the pseudo handle of the current thread, or the main thread: accepted)
    struct sched_param sp;
    int policy;
    if (pthread_getschedparam(t->th, &policy, &sp) == 0) {
        int lo = sched_get_priority_min(policy), hi = sched_get_priority_max(policy);
        int mid = (lo + hi) / 2;
        int p = priority >= 15 ? hi : priority <= -15 ? lo : mid + priority * (hi - lo) / 30;
        sp.sched_priority = p;
        pthread_setschedparam(t->th, policy, &sp);
    }
    return 1;
}

extern "C" void HULK_HOST_STDCALL hulk_host_Sleep(hulk_u32 ms) {
    if (!ms) {
        sched_yield();
        return;
    }
    struct timespec ts = {(time_t)(ms / 1000), (long)(ms % 1000) * 1000000L};
    while (nanosleep(&ts, &ts) == -1 && errno == EINTR) {
    }
}

// ---------------------------------------------------------------------------------------------------------------
// Semaphores and events
extern "C" void* HULK_HOST_STDCALL hulk_host_CreateSemaphoreA(void* sa, int initial, int maximum, const char* name) {
    (void)sa; (void)name;
    if (maximum <= 0 || initial < 0 || initial > maximum) {
        hulk_host_SetLastError(HULK_ERROR_INVALID_PARAMETER);
        return 0;
    }
    SemaphoreObj* s = new SemaphoreObj;
    obj_init(s, K_SEMAPHORE, 1);
    s->count = initial;
    s->maximum = maximum;
    return s;
}

extern "C" int HULK_HOST_STDCALL hulk_host_ReleaseSemaphore(void* h, int count, int* previous) {
    SemaphoreObj* s = as<SemaphoreObj>(h, K_SEMAPHORE);
    if (!s || count <= 0) {
        hulk_host_SetLastError(s ? HULK_ERROR_INVALID_PARAMETER : HULK_ERROR_INVALID_HANDLE);
        return 0;
    }
    pthread_mutex_lock(&s->mu);
    if (s->count + count > s->maximum) {
        pthread_mutex_unlock(&s->mu);
        hulk_host_SetLastError(HULK_ERROR_TOO_MANY_POSTS);
        return 0;
    }
    if (previous)
        *previous = s->count;
    s->count += count;
    pthread_cond_broadcast(&s->cv);
    pthread_mutex_unlock(&s->mu);
    return 1;
}

extern "C" void* hulk_host_CreateEventA(void* sa, int manual_reset, int initial, const char* name) {
    (void)sa; (void)name;
    EventObj* e = new EventObj;
    obj_init(e, K_EVENT, 1);
    e->signaled = initial != 0;
    e->manual = manual_reset != 0;
    return e;
}

extern "C" int hulk_host_SetEvent(void* h) {
    EventObj* e = as<EventObj>(h, K_EVENT);
    if (!e) {
        hulk_host_SetLastError(HULK_ERROR_INVALID_HANDLE);
        return 0;
    }
    pthread_mutex_lock(&e->mu);
    e->signaled = 1;
    pthread_cond_broadcast(&e->cv);
    pthread_mutex_unlock(&e->mu);
    return 1;
}

extern "C" int hulk_host_ResetEvent(void* h) {
    EventObj* e = as<EventObj>(h, K_EVENT);
    if (!e) {
        hulk_host_SetLastError(HULK_ERROR_INVALID_HANDLE);
        return 0;
    }
    pthread_mutex_lock(&e->mu);
    e->signaled = 0;
    pthread_mutex_unlock(&e->mu);
    return 1;
}

extern "C" hulk_u32 HULK_HOST_STDCALL hulk_host_WaitForSingleObject(void* h, hulk_u32 ms) {
    HulkHostObject* o = (h && h != HULK_INVALID_HANDLE_VALUE) ? (HulkHostObject*)h : 0;
    if (!o || (o->kind != K_THREAD && o->kind != K_SEMAPHORE && o->kind != K_EVENT)) {
        hulk_host_SetLastError(HULK_ERROR_INVALID_HANDLE);
        return HULK_WAIT_FAILED;
    }
    int ok;
    pthread_mutex_lock(&o->mu);
    if (o->kind == K_THREAD) {
        ThreadObj* t = (ThreadObj*)o;
        ok = wait_until(o, ms, [t] { return t->done != 0; });
    } else if (o->kind == K_SEMAPHORE) {
        SemaphoreObj* s = (SemaphoreObj*)o;
        ok = wait_until(o, ms, [s] { return s->count > 0; });
        if (ok)
            s->count--;
    } else {
        EventObj* e = (EventObj*)o;
        ok = wait_until(o, ms, [e] { return e->signaled != 0; });
        if (ok && !e->manual)
            e->signaled = 0;
    }
    pthread_mutex_unlock(&o->mu);
    return ok ? HULK_WAIT_OBJECT_0 : HULK_WAIT_TIMEOUT;
}

// ---------------------------------------------------------------------------------------------------------------
// Critical sections: the caller's storage (24 bytes on x86 Windows, the shims give 32) holds a pointer to a
// recursive mutex of ours (pthread_mutex_t is 64 bytes on macOS)
struct CsBox {
    pthread_mutex_t mu;
};

extern "C" void HULK_HOST_STDCALL hulk_host_InitializeCriticalSection(void* cs) {
    CsBox* b = new CsBox;
    pthread_mutexattr_t a;
    pthread_mutexattr_init(&a);
    pthread_mutexattr_settype(&a, PTHREAD_MUTEX_RECURSIVE);
    pthread_mutex_init(&b->mu, &a);
    pthread_mutexattr_destroy(&a);
    memcpy(cs, &b, sizeof(b));
}

static CsBox* cs_box(void* cs) {
    CsBox* b;
    memcpy(&b, cs, sizeof(b));
    return b;
}

extern "C" void HULK_HOST_STDCALL hulk_host_EnterCriticalSection(void* cs) { pthread_mutex_lock(&cs_box(cs)->mu); }
extern "C" void HULK_HOST_STDCALL hulk_host_LeaveCriticalSection(void* cs) { pthread_mutex_unlock(&cs_box(cs)->mu); }

extern "C" void HULK_HOST_STDCALL hulk_host_DeleteCriticalSection(void* cs) {
    CsBox* b = cs_box(cs);
    if (b) {
        pthread_mutex_destroy(&b->mu);
        delete b;
        memset(cs, 0, sizeof(b));
    }
}

// ---------------------------------------------------------------------------------------------------------------
// Fibers: our own context switch (callee-saved registers on the fiber's stack, then the stack pointer swaps):
// AArch64 (macOS, Linux) and x86-64 System V. ucontext is deprecated on macOS and slow everywhere (signal masks).
struct Fiber {
    void* sp;            // saved stack pointer while not running
    void* data;          // ConvertThreadToFiber / CreateFiber's parameter
    void (*start)(void*);
    void* stack;         // mmap'd stack (0 for a converted thread)
    size_t stack_size;
};

static thread_local Fiber* t_fiber;

extern "C" void hulk_fiber_switch(void** save_sp, void* new_sp);   // the assembly below
extern "C" void hulk_fiber_trampoline(void);

extern "C" void hulk_fiber_entry(Fiber* f) {
    f->start(f->data);
    // a fiber routine that returns ends its thread, as on Windows
    hulk_host_ExitThread(0);
}

#if defined(__APPLE__)
#define HULK_SYM(x) "_" #x
#else
#define HULK_SYM(x) #x
#endif

#if defined(__aarch64__)
// frame (176 bytes, from sp up): x19..x28 (10), x29, x30, d8..d15 (8), 16 spare
__asm__(".text\n"
        ".p2align 2\n"
        ".globl " HULK_SYM(hulk_fiber_switch) "\n"
        HULK_SYM(hulk_fiber_switch) ":\n"
        "  sub sp, sp, #176\n"
        "  stp x19, x20, [sp, #0]\n"
        "  stp x21, x22, [sp, #16]\n"
        "  stp x23, x24, [sp, #32]\n"
        "  stp x25, x26, [sp, #48]\n"
        "  stp x27, x28, [sp, #64]\n"
        "  stp x29, x30, [sp, #80]\n"
        "  stp d8, d9, [sp, #96]\n"
        "  stp d10, d11, [sp, #112]\n"
        "  stp d12, d13, [sp, #128]\n"
        "  stp d14, d15, [sp, #144]\n"
        "  mov x9, sp\n"
        "  str x9, [x0]\n"
        "  mov sp, x1\n"
        "  ldp x19, x20, [sp, #0]\n"
        "  ldp x21, x22, [sp, #16]\n"
        "  ldp x23, x24, [sp, #32]\n"
        "  ldp x25, x26, [sp, #48]\n"
        "  ldp x27, x28, [sp, #64]\n"
        "  ldp x29, x30, [sp, #80]\n"
        "  ldp d8, d9, [sp, #96]\n"
        "  ldp d10, d11, [sp, #112]\n"
        "  ldp d12, d13, [sp, #128]\n"
        "  ldp d14, d15, [sp, #144]\n"
        "  add sp, sp, #176\n"
        "  ret\n"
        ".globl " HULK_SYM(hulk_fiber_trampoline) "\n"
        HULK_SYM(hulk_fiber_trampoline) ":\n"
        "  mov x0, x19\n"
        "  bl " HULK_SYM(hulk_fiber_entry) "\n"
        "  brk #1\n");
enum { FRAME_BYTES = 176 };
static void* initial_frame(Fiber* f, char* top) {
    uint64_t* fr = (uint64_t*)(top - FRAME_BYTES);   // top is 16-byte aligned, so is the frame
    memset(fr, 0, FRAME_BYTES);
    fr[0] = (uint64_t)(uintptr_t)f;                          // x19: the fiber
    fr[11] = (uint64_t)(uintptr_t)&hulk_fiber_trampoline;    // x30: where the first switch returns
    return fr;
}
#elif defined(__x86_64__)
// frame (from rsp up): r15, r14, r13, r12, rbx, rbp, return address
__asm__(".text\n"
        ".globl " HULK_SYM(hulk_fiber_switch) "\n"
        HULK_SYM(hulk_fiber_switch) ":\n"
        "  pushq %rbp\n"
        "  pushq %rbx\n"
        "  pushq %r12\n"
        "  pushq %r13\n"
        "  pushq %r14\n"
        "  pushq %r15\n"
        "  movq %rsp, (%rdi)\n"
        "  movq %rsi, %rsp\n"
        "  popq %r15\n"
        "  popq %r14\n"
        "  popq %r13\n"
        "  popq %r12\n"
        "  popq %rbx\n"
        "  popq %rbp\n"
        "  ret\n"
        ".globl " HULK_SYM(hulk_fiber_trampoline) "\n"
        HULK_SYM(hulk_fiber_trampoline) ":\n"
        "  movq %rbx, %rdi\n"
        "  call " HULK_SYM(hulk_fiber_entry) "\n"
        "  ud2\n");
static void* initial_frame(Fiber* f, char* top) {
    // after `ret` into the trampoline rsp must be 8 mod 16 (as on entry to any function), so the frame's 7 words
    // start 8 below a 16-byte boundary
    uint64_t* fr = (uint64_t*)(top - 8 - 7 * 8);
    memset(fr, 0, 7 * 8);
    fr[4] = (uint64_t)(uintptr_t)f;                          // rbx: the fiber
    fr[6] = (uint64_t)(uintptr_t)&hulk_fiber_trampoline;     // return address
    return fr;
}
#else
#error "win32_posix.cpp: no fiber switch for this architecture"
#endif

extern "C" void* HULK_HOST_STDCALL hulk_host_ConvertThreadToFiber(void* param) {
    if (t_fiber) {
        hulk_host_SetLastError(HULK_ERROR_ALREADY_EXISTS);   // (ERROR_ALREADY_FIBER is 1280; the shims only test null)
        return 0;
    }
    Fiber* f = new Fiber();
    f->data = param;
    t_fiber = f;
    return f;
}

extern "C" void* HULK_HOST_STDCALL hulk_host_CreateFiber(hulk_u32 stack, void* start, void* param) {
    size_t page = (size_t)sysconf(_SC_PAGESIZE);
    size_t size = stack < 0x40000 ? 0x40000 : stack;
    size = (size + page - 1) & ~(page - 1);
    // one guard page below the stack
    char* mem = (char*)mmap(0, size + page, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANON, -1, 0);
    if (mem == (char*)MAP_FAILED) {
        hulk_host_SetLastError(HULK_ERROR_NOT_ENOUGH_MEMORY);
        return 0;
    }
    mprotect(mem, page, PROT_NONE);
    Fiber* f = new Fiber();
    f->data = param;
    f->start = (void (*)(void*))start;
    f->stack = mem;
    f->stack_size = size + page;
    char* top = (char*)(((uintptr_t)(mem + size + page)) & ~(uintptr_t)15);
    f->sp = initial_frame(f, top);
    return f;
}

extern "C" void HULK_HOST_STDCALL hulk_host_SwitchToFiber(void* fiber) {
    Fiber* to = (Fiber*)fiber;
    Fiber* from = t_fiber;
    if (!to || !from || to == from)
        return;
    t_fiber = to;
    hulk_fiber_switch(&from->sp, to->sp);
}

extern "C" void HULK_HOST_STDCALL hulk_host_DeleteFiber(void* fiber) {
    Fiber* f = (Fiber*)fiber;
    if (!f)
        return;
    if (f == t_fiber) {   // deleting the running fiber ends the thread (Win32)
        hulk_host_ExitThread(0);
        return;
    }
    if (f->stack)
        munmap(f->stack, f->stack_size);
    delete f;
}

extern "C" void* hulk_host_GetFiberData(void) { return t_fiber ? t_fiber->data : 0; }
extern "C" void* hulk_host_GetCurrentFiber(void) { return t_fiber; }

// ---------------------------------------------------------------------------------------------------------------
// Files (the path is already a host path: crt_glue.cpp hulk_crt_host_path maps the game's drive letters)
extern "C" void* HULK_HOST_STDCALL hulk_host_CreateFileA(const char* path, hulk_u32 access, hulk_u32 share, void* sa,
                                                        hulk_u32 disposition, hulk_u32 flags, void* templ) {
    (void)share; (void)sa; (void)flags; (void)templ;
    if (!path) {
        hulk_host_SetLastError(HULK_ERROR_PATH_NOT_FOUND);
        return HULK_INVALID_HANDLE_VALUE;
    }
    int rw = (access & HULK_GENERIC_READ) && (access & HULK_GENERIC_WRITE) ? O_RDWR
             : (access & HULK_GENERIC_WRITE) ? O_WRONLY : O_RDONLY;
    int of;
    switch (disposition) {
    case HULK_CREATE_NEW: of = O_CREAT | O_EXCL; break;
    case HULK_CREATE_ALWAYS: of = O_CREAT | O_TRUNC; break;
    case HULK_OPEN_EXISTING: of = 0; break;
    case HULK_OPEN_ALWAYS: of = O_CREAT; break;
    case HULK_TRUNCATE_EXISTING: of = O_TRUNC; break;
    default:
        hulk_host_SetLastError(HULK_ERROR_INVALID_PARAMETER);
        return HULK_INVALID_HANDLE_VALUE;
    }
    struct stat st;
    int existed = stat(path, &st) == 0;
    if (existed && S_ISDIR(st.st_mode)) {
        hulk_host_SetLastError(HULK_ERROR_ACCESS_DENIED);
        return HULK_INVALID_HANDLE_VALUE;
    }
    int fd = open(path, rw | of | O_CLOEXEC, 0644);
    if (fd < 0) {
        hulk_host_SetLastError(errno == EEXIST ? HULK_ERROR_FILE_EXISTS : errno_to_win32(errno));
        return HULK_INVALID_HANDLE_VALUE;
    }
    FileObj* f = new FileObj;
    obj_init(f, K_FILE, 1);
    f->fd = fd;
    // CREATE_ALWAYS / OPEN_ALWAYS over an existing file succeed with ERROR_ALREADY_EXISTS
    hulk_host_SetLastError(existed && (disposition == HULK_CREATE_ALWAYS || disposition == HULK_OPEN_ALWAYS)
                           ? HULK_ERROR_ALREADY_EXISTS : 0);
    return f;
}

// OVERLAPPED {Internal, InternalHigh, Offset, OffsetHigh, hEvent}: Internal/InternalHigh are pointer-sized
struct HostOverlapped {
    uintptr_t internal, internal_high;
    hulk_u32 offset, offset_high;
    void* event;
};

static int file_io(void* h, void* buf, hulk_u32 n, hulk_u32* done, void* overlapped, int write) {
    FileObj* f = as<FileObj>(h, K_FILE);
    if (done)
        *done = 0;
    if (!f) {
        hulk_host_SetLastError(HULK_ERROR_INVALID_HANDLE);
        return 0;
    }
    HostOverlapped* ov = (HostOverlapped*)overlapped;
    size_t total = 0;
    while (total < n) {
        ssize_t r;
        if (ov) {
            off_t at = (off_t)(((unsigned long long)ov->offset_high << 32) | ov->offset) + (off_t)total;
            r = write ? pwrite(f->fd, (char*)buf + total, n - total, at) : pread(f->fd, (char*)buf + total, n - total, at);
        } else {
            r = write ? ::write(f->fd, (char*)buf + total, n - total) : ::read(f->fd, (char*)buf + total, n - total);
        }
        if (r < 0) {
            if (errno == EINTR)
                continue;
            hulk_host_SetLastError(errno_to_win32(errno));
            return 0;
        }
        if (r == 0)
            break;   // end of file: a short read succeeds
        total += (size_t)r;
    }
    if (done)
        *done = (hulk_u32)total;
    if (ov) {
        ov->internal = 0;
        ov->internal_high = total;
        if (ov->event)
            hulk_host_SetEvent(ov->event);
    }
    return 1;
}

extern "C" int HULK_HOST_STDCALL hulk_host_ReadFile(void* h, void* buf, hulk_u32 n, hulk_u32* done, void* overlapped) {
    return file_io(h, buf, n, done, overlapped, 0);
}

extern "C" int HULK_HOST_STDCALL hulk_host_WriteFile(void* h, const void* buf, hulk_u32 n, hulk_u32* done,
                                                     void* overlapped) {
    return file_io(h, (void*)buf, n, done, overlapped, 1);
}

extern "C" hulk_u32 HULK_HOST_STDCALL hulk_host_SetFilePointer(void* h, int lo, int* hi, hulk_u32 method) {
    FileObj* f = as<FileObj>(h, K_FILE);
    if (!f) {
        hulk_host_SetLastError(HULK_ERROR_INVALID_HANDLE);
        return HULK_INVALID_SET_FILE_POINTER;
    }
    long long off = hi ? (long long)(((unsigned long long)(unsigned)*hi << 32) | (unsigned)lo) : (long long)lo;
    int whence = method == HULK_FILE_BEGIN ? SEEK_SET : method == HULK_FILE_CURRENT ? SEEK_CUR : SEEK_END;
    off_t r = lseek(f->fd, (off_t)off, whence);
    if (r < 0) {
        hulk_host_SetLastError(errno == EINVAL ? HULK_ERROR_NEGATIVE_SEEK : errno_to_win32(errno));
        return HULK_INVALID_SET_FILE_POINTER;
    }
    if (hi)
        *hi = (int)((unsigned long long)r >> 32);
    hulk_host_SetLastError(0);
    return (hulk_u32)r;
}

extern "C" hulk_u32 HULK_HOST_STDCALL hulk_host_GetFileSize(void* h, hulk_u32* hi) {
    FileObj* f = as<FileObj>(h, K_FILE);
    struct stat st;
    if (!f || fstat(f->fd, &st) != 0) {
        hulk_host_SetLastError(f ? errno_to_win32(errno) : HULK_ERROR_INVALID_HANDLE);
        return 0xffffffffu;
    }
    if (hi)
        *hi = (hulk_u32)((unsigned long long)st.st_size >> 32);
    return (hulk_u32)st.st_size;
}

extern "C" int HULK_HOST_STDCALL hulk_host_SetEndOfFile(void* h) {
    FileObj* f = as<FileObj>(h, K_FILE);
    if (!f) {
        hulk_host_SetLastError(HULK_ERROR_INVALID_HANDLE);
        return 0;
    }
    off_t at = lseek(f->fd, 0, SEEK_CUR);
    if (at < 0 || ftruncate(f->fd, at) != 0) {
        hulk_host_SetLastError(errno_to_win32(errno));
        return 0;
    }
    return 1;
}

extern "C" int HULK_HOST_STDCALL hulk_host_CloseHandle(void* h) {
    HulkHostObject* o = (h && h != HULK_INVALID_HANDLE_VALUE) ? (HulkHostObject*)h : 0;
    if (!o || (o->kind != K_THREAD && o->kind != K_SEMAPHORE && o->kind != K_EVENT && o->kind != K_FILE)) {
        hulk_host_SetLastError(HULK_ERROR_INVALID_HANDLE);
        return 0;
    }
    if (o->kind == K_FILE)
        close(((FileObj*)o)->fd);
    obj_release(o);
    return 1;
}

static void put_u64(void* p, unsigned long long v) {
    if (p)
        memcpy(p, &v, 8);   // ULARGE_INTEGER, little-endian
}

extern "C" int HULK_HOST_STDCALL hulk_host_GetDiskFreeSpaceExA(const char* path, void* avail, void* total, void* free_) {
    struct statvfs s;
    if (statvfs(path && *path ? path : ".", &s) != 0) {
        hulk_host_SetLastError(errno_to_win32(errno));
        return 0;
    }
    put_u64(avail, (unsigned long long)s.f_bavail * s.f_frsize);
    put_u64(total, (unsigned long long)s.f_blocks * s.f_frsize);
    put_u64(free_, (unsigned long long)s.f_bfree * s.f_frsize);
    return 1;
}

extern "C" int HULK_HOST_STDCALL hulk_host_CreateDirectoryA(const char* path, void* sa) {
    (void)sa;
    if (mkdir(path, 0755) != 0) {
        hulk_host_SetLastError(errno == EEXIST ? HULK_ERROR_ALREADY_EXISTS : errno_to_win32(errno));
        return 0;
    }
    return 1;
}

extern "C" hulk_u32 HULK_HOST_STDCALL hulk_host_GetFileAttributesA(const char* path) {
    struct stat st;
    if (!path || stat(path, &st) != 0) {
        hulk_host_SetLastError(path ? errno_to_win32(errno) : HULK_ERROR_PATH_NOT_FOUND);
        return HULK_INVALID_FILE_ATTRIBUTES;
    }
    hulk_u32 a = S_ISDIR(st.st_mode) ? HULK_FILE_ATTRIBUTE_DIRECTORY : HULK_FILE_ATTRIBUTE_NORMAL;
    if (!(st.st_mode & S_IWUSR))
        a |= 1;   // FILE_ATTRIBUTE_READONLY
    return a;
}

// ---------------------------------------------------------------------------------------------------------------
// Time
extern "C" int HULK_HOST_STDCALL hulk_host_QueryPerformanceFrequency(void* freq) {
    put_u64(freq, 1000000000ull);   // nanoseconds
    return 1;
}

extern "C" int HULK_HOST_STDCALL hulk_host_QueryPerformanceCounter(void* count) {
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    put_u64(count, (unsigned long long)ts.tv_sec * 1000000000ull + (unsigned long long)ts.tv_nsec);
    return 1;
}

// SYSTEMTIME: wYear, wMonth, wDayOfWeek, wDay, wHour, wMinute, wSecond, wMilliseconds (16-bit words)
extern "C" void HULK_HOST_STDCALL hulk_host_GetLocalTime(void* system_time) {
    struct timeval tv;
    gettimeofday(&tv, 0);
    time_t t = tv.tv_sec;
    struct tm lt;
    localtime_r(&t, &lt);
    unsigned short w[8] = {(unsigned short)(lt.tm_year + 1900), (unsigned short)(lt.tm_mon + 1),
                           (unsigned short)lt.tm_wday, (unsigned short)lt.tm_mday, (unsigned short)lt.tm_hour,
                           (unsigned short)lt.tm_min, (unsigned short)lt.tm_sec, (unsigned short)(tv.tv_usec / 1000)};
    memcpy(system_time, w, sizeof(w));
}

// ---------------------------------------------------------------------------------------------------------------
// Memory: reserve/commit as one anonymous mapping (MEM_COMMIT 0x1000, MEM_RESERVE 0x2000; PAGE_READWRITE 4,
// PAGE_EXECUTE_READWRITE 0x40). A requested address is a hint only: the native builds never map at XBE addresses.
extern "C" void* HULK_HOST_STDCALL hulk_host_VirtualAlloc(void* addr, hulk_u32 size, hulk_u32 type, hulk_u32 protect) {
    (void)type;
    int prot = PROT_READ | PROT_WRITE | ((protect & 0xf0) ? PROT_EXEC : 0);
    void* p = mmap(addr, size, prot, MAP_PRIVATE | MAP_ANON, -1, 0);
    if (p == MAP_FAILED) {
        hulk_host_SetLastError(HULK_ERROR_NOT_ENOUGH_MEMORY);
        return 0;
    }
    return p;
}

#endif  // !_WIN32

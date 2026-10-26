// The entry point of the native builds on macOS and Linux (docs/native-mac.md "Host side"): what
// src/platform/sdl/xdk/startup.cpp does for the Wine build, on POSIX. Host side (system headers, the host's ABI);
// every symbol it shares with the game side has C linkage. Not linked into an image yet.
//
//   * the start-up trace (HULK_TRACE_FILE, default hulk-startup-trace.txt): the same line formats as startup.cpp
//     ("first", "init", "skip", "missing", "crash", "end", "called"), so tools/wine_run.py-style readers work on both;
//   * the game's C++ dynamic initializers in the XBE's order (hulk_game_initializers[], written by the native link
//     like build/native/link/startup.s), then the replay's start-up hook, the game's main and the atexit list;
//   * a crash report: SIGSEGV/SIGBUS/SIGILL/SIGFPE/SIGTRAP on an alternate stack, the registers that matter, the
//     frame-pointer chain and the symbol of each return address (dladdr);
//   * a call to a symbol the image lacks (the native link's stubs call hulk_native_missing(name));
//   * HULK_HANG=N: after N seconds, a sample of every thread's pc / fp / frame chain (macOS: Mach thread states),
//     then exit 6.
//
// What the Wine build's start-up has and this one has not, on purpose: the XBE window (the XBE's data sections
// mapped at their own addresses: arm64 macOS refuses a page-zero below 4 GB, so no image can map them; the sources
// that name data by address need named data instead, docs/wine-build.md "Bridges to remove"), the x87 control word
// (no x87: the FPU is set to round-to-nearest with denormals kept, as the game's 0x027f word has it), and the
// HULK_TRACE_FUNCS entry/exit hooks (x86 register images).
#if !defined(_WIN32)
#include <dlfcn.h>
#include <pthread.h>
#include <signal.h>
#include <stdarg.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#if defined(__APPLE__)
#include <mach/mach.h>
#include <sys/ucontext.h>
#else
#include <sys/mman.h>
#include <ucontext.h>
#endif

typedef unsigned int hulk_u32;

extern "C" {
// written by the native link (as build/native/link/startup.s for the Wine build)
typedef void (*hulk_init_fn)(void);
extern hulk_init_fn hulk_game_initializers[];
extern const hulk_u32 hulk_game_initializer_addrs[];
extern const hulk_u32 hulk_game_initializer_count;
int hulk_game_main(void);
// the shim and the CRT glue (game side, C linkage)
typedef void (*hulk_xdk_first_fn)(const char* name, const void* caller);
extern hulk_xdk_first_fn hulk_xdk_first_call_sink;
hulk_u32 hulk_xdk_called(const char** names, hulk_u32* calls, hulk_u32 max);
// optional: weak no-op definitions here, replaced by the CRT glue's atexit list and the replay hooks (a Wine-build
// bridge) when the image has them
__attribute__((weak)) void hulk_crt_run_atexit(void) {}
__attribute__((weak)) void hulk_replay_startup(void) {}
}

static FILE* g_trace;
static const char* volatile g_phase = "start";
static hulk_u32 g_seq;
static pthread_mutex_t g_trace_mu = PTHREAD_MUTEX_INITIALIZER;

static void trace_line(const char* fmt, ...) __attribute__((format(printf, 1, 2)));
static void trace_line(const char* fmt, ...) {
    char buf[512];
    va_list ap;
    va_start(ap, fmt);
    int n = vsnprintf(buf, sizeof(buf) - 2, fmt, ap);
    va_end(ap);
    if (n < 0 || n > (int)sizeof(buf) - 2)
        n = sizeof(buf) - 2;
    buf[n] = '\n';
    buf[n + 1] = 0;
    pthread_mutex_lock(&g_trace_mu);
    if (g_trace) {
        fputs(buf, g_trace);
        fflush(g_trace);
    }
    pthread_mutex_unlock(&g_trace_mu);
}

// the graphics backend's and the shims' log: one trace line "gfx <line>" per call
extern "C" void hulk_native_log(const char* line) {
    char buf[480];
    int n = 0;
    while (line[n] && line[n] != '\n' && n < (int)sizeof(buf) - 1) {
        buf[n] = line[n];
        n++;
    }
    buf[n] = 0;
    trace_line("gfx %s", buf);
}

static void first_call(const char* name, const void* caller) {
    trace_line("first %u %s caller=%p phase=%s", ++g_seq, name, caller, g_phase);
}

static const char* sym_of(uintptr_t pc, char* buf, size_t n) {
    Dl_info di;
    if (pc && dladdr((void*)pc, &di) && di.dli_sname) {
        snprintf(buf, n, "%s+0x%lx", di.dli_sname, (unsigned long)(pc - (uintptr_t)di.dli_saddr));
        return buf;
    }
    return "?";
}

// the frame-pointer chain (AArch64 and x86-64 both keep [fp] = caller's fp, [fp + 8] = return address)
static void frames(uintptr_t fp) {
    uintptr_t first = fp;
    char s[256];
    for (int i = 0; i < 32 && fp && (fp & 7) == 0 && fp - first < 0x1000000; i++) {
        const uintptr_t* f = (const uintptr_t*)fp;
        uintptr_t ret = f[1];
#if defined(__aarch64__) && defined(__APPLE__)
        ret &= 0x0000ffffffffffffull;   // (no pointer authentication on arm64, but keep the address bits only)
#endif
        trace_line("frame %d ret=%p %s", i, (void*)ret, sym_of(ret, s, sizeof(s)));
        if (f[0] <= fp)
            break;
        fp = f[0];
    }
}

static void summary(const char* how, hulk_u32 code) {
    static const char* names[1024];
    static hulk_u32 calls[1024];
    hulk_u32 n = hulk_xdk_called(names, calls, 1024);
    trace_line("end %s code=%u phase=%s imports_called=%u", how, code, g_phase, n);
    for (hulk_u32 i = 0; i < n && i < 1024; i++)
        trace_line("called %s %u", names[i], calls[i]);
    pthread_mutex_lock(&g_trace_mu);
    if (g_trace)
        fclose(g_trace);
    g_trace = 0;
    pthread_mutex_unlock(&g_trace_mu);
}

// A call to a symbol the image still lacks (the native link's stubs: `hulk_native_missing("name")`).
extern "C" void hulk_native_missing(const char* name) {
    char s[256];
    uintptr_t caller = (uintptr_t)__builtin_return_address(0);
    trace_line("missing %s caller=%p %s phase=%s", name, (void*)caller, sym_of(caller, s, sizeof(s)), g_phase);
    frames((uintptr_t)__builtin_frame_address(0));
    summary("missing", 3);
    _exit(3);
}

// ---------------------------------------------------------------------------------------------------------------
// Crashes
struct Regs {
    uintptr_t pc, sp, fp, lr;
};

static Regs regs_of(void* uctx) {
    Regs r = {0, 0, 0, 0};
    ucontext_t* uc = (ucontext_t*)uctx;
#if defined(__APPLE__) && defined(__aarch64__)
    r.pc = (uintptr_t)uc->uc_mcontext->__ss.__pc;
    r.sp = (uintptr_t)uc->uc_mcontext->__ss.__sp;
    r.fp = (uintptr_t)uc->uc_mcontext->__ss.__fp;
    r.lr = (uintptr_t)uc->uc_mcontext->__ss.__lr;
#elif defined(__APPLE__) && defined(__x86_64__)
    r.pc = (uintptr_t)uc->uc_mcontext->__ss.__rip;
    r.sp = (uintptr_t)uc->uc_mcontext->__ss.__rsp;
    r.fp = (uintptr_t)uc->uc_mcontext->__ss.__rbp;
#elif defined(__linux__) && defined(__aarch64__)
    r.pc = (uintptr_t)uc->uc_mcontext.pc;
    r.sp = (uintptr_t)uc->uc_mcontext.sp;
    r.fp = (uintptr_t)uc->uc_mcontext.regs[29];
    r.lr = (uintptr_t)uc->uc_mcontext.regs[30];
#elif defined(__linux__) && defined(__x86_64__)
    r.pc = (uintptr_t)uc->uc_mcontext.gregs[REG_RIP];
    r.sp = (uintptr_t)uc->uc_mcontext.gregs[REG_RSP];
    r.fp = (uintptr_t)uc->uc_mcontext.gregs[REG_RBP];
#endif
    return r;
}

static void crash_handler(int sig, siginfo_t* si, void* uctx) {
    static volatile sig_atomic_t in;
    if (in++)
        _exit(5);   // (a crash inside the report)
    Regs r = regs_of(uctx);
    char s[256], t[256];
    trace_line("crash signal=%d addr=%p pc=%p %s phase=%s", sig, si ? si->si_addr : 0, (void*)r.pc,
               sym_of(r.pc, s, sizeof(s)), g_phase);
    trace_line("regs sp=%p fp=%p lr=%p %s", (void*)r.sp, (void*)r.fp, (void*)r.lr, sym_of(r.lr, t, sizeof(t)));
    if (si && (uintptr_t)si->si_addr >= 0x1000 && (uintptr_t)si->si_addr < (1ull << 32))
        trace_line("hint addr below 4 GB: a pointer that went through 32 bits (a truncation, or game data read as an "
                   "address); the low 4 GB is never mapped (macOS page zero, Linux low_4gb_reserve)");
    frames(r.fp);
    summary("crash", (hulk_u32)sig);
    _exit(4);
}

static void install_crash_handler(void) {
    static char altstack[1 << 16];
    stack_t ss;
    ss.ss_sp = altstack;
    ss.ss_size = sizeof(altstack);
    ss.ss_flags = 0;
    sigaltstack(&ss, 0);
    struct sigaction sa;
    memset(&sa, 0, sizeof(sa));
    sa.sa_sigaction = crash_handler;
    sa.sa_flags = SA_SIGINFO | SA_ONSTACK;
    sigemptyset(&sa.sa_mask);
    const int sigs[] = {SIGSEGV, SIGBUS, SIGILL, SIGFPE, SIGTRAP};
    for (int s : sigs)
        sigaction(s, &sa, 0);
}

// ---------------------------------------------------------------------------------------------------------------
// HULK_HANG=N: sample every thread after N seconds
static hulk_u32 env_u32(const char* name, hulk_u32 dflt) {
    const char* v = getenv(name);
    if (!v || !*v)
        return dflt;
    hulk_u32 n = 0;
    for (; *v >= '0' && *v <= '9'; v++)
        n = n * 10 + (hulk_u32)(*v - '0');
    return n;
}

static void* watchdog(void* arg) {
    sleep((unsigned)(uintptr_t)arg);
    hulk_u32 samples = env_u32("HULK_HANG_SAMPLES", 4);
#if defined(__APPLE__)
    thread_act_array_t threads;
    mach_msg_type_number_t n = 0;
    mach_port_t self = mach_thread_self();
    for (hulk_u32 s = 0; s < samples; s++) {
        if (task_threads(mach_task_self(), &threads, &n) != KERN_SUCCESS)
            break;
        for (mach_msg_type_number_t i = 0; i < n; i++) {
            if (threads[i] == self)
                continue;
            thread_suspend(threads[i]);
            char sym[256];
#if defined(__aarch64__)
            arm_thread_state64_t st;
            mach_msg_type_number_t cnt = ARM_THREAD_STATE64_COUNT;
            if (thread_get_state(threads[i], ARM_THREAD_STATE64, (thread_state_t)&st, &cnt) == KERN_SUCCESS) {
                uintptr_t pc = (uintptr_t)arm_thread_state64_get_pc(st), fp = (uintptr_t)arm_thread_state64_get_fp(st);
                trace_line("hang sample %u thread %u phase=%s pc=%p %s", s, i, g_phase, (void*)pc, sym_of(pc, sym, sizeof(sym)));
                frames(fp);
            }
#elif defined(__x86_64__)
            x86_thread_state64_t st;
            mach_msg_type_number_t cnt = x86_THREAD_STATE64_COUNT;
            if (thread_get_state(threads[i], x86_THREAD_STATE64, (thread_state_t)&st, &cnt) == KERN_SUCCESS) {
                trace_line("hang sample %u thread %u phase=%s pc=%p %s", s, i, g_phase, (void*)st.__rip,
                           sym_of(st.__rip, sym, sizeof(sym)));
                frames(st.__rbp);
            }
#endif
            thread_resume(threads[i]);
            mach_port_deallocate(mach_task_self(), threads[i]);
        }
        vm_deallocate(mach_task_self(), (vm_address_t)threads, n * sizeof(thread_act_t));
        usleep(250000);
    }
#else
    (void)samples;
    trace_line("hang phase=%s (no thread sampling on this host)", g_phase);
#endif
    summary("hang", 0);
    _exit(6);
    return 0;
}

#if defined(__linux__)
// macOS keeps the low 4 GB unmapped (the 64-bit page zero); Linux only keeps the first 64 KB (vm.mmap_min_addr). So a
// pointer cut to 32 bits, or a 32-bit game value used as an address, faults here too instead of reading whatever
// happens to be mapped there: every free range below 4 GB is reserved PROT_NONE before the game runs (a constructor,
// ahead of the C++ initializers). Needs a PIE image (the default on SteamOS's toolchains): a non-PIE one sits at
// 0x400000, and what is mapped already is left alone. HULK_LOW_4GB=0 turns it off.
static unsigned g_low_reserved_mb;
__attribute__((constructor(101))) static void low_4gb_reserve(void) {
    const char* e = getenv("HULK_LOW_4GB");
    if (e && *e == '0')
        return;
    const uintptr_t top = 1ull << 32;
    uintptr_t lo = 1 << 16;
    if (FILE* f = fopen("/proc/sys/vm/mmap_min_addr", "r")) {
        unsigned long v;
        if (fscanf(f, "%lu", &v) == 1 && v > lo)
            lo = (v + 0xffff) & ~(uintptr_t)0xffff;
        fclose(f);
    }
    // halve the request until it fits between existing mappings (MAP_FIXED_NOREPLACE never replaces one)
    for (uintptr_t at = lo; at < top;) {
        uintptr_t len = top - at;
        void* p = MAP_FAILED;
        while (len >= (1 << 16)) {
            p = mmap((void*)at, len, PROT_NONE, MAP_PRIVATE | MAP_ANONYMOUS | MAP_NORESERVE | MAP_FIXED_NOREPLACE, -1, 0);
            if (p != MAP_FAILED && (uintptr_t)p != at) {   // (an old kernel without NOREPLACE: a hint, not a fixed map)
                munmap(p, len);
                return;
            }
            if (p != MAP_FAILED)
                break;
            len >>= 1;
        }
        if (p == MAP_FAILED)
            at += 1 << 16;   // something is mapped at AT: step past it
        else {
            g_low_reserved_mb += (unsigned)(len >> 20);
            at += len;
        }
    }
}
#endif

// The FPU as the game's x87 control word 0x027f has it: round to nearest, exceptions masked, denormals kept
// (AArch64: FPCR.FZ, FZ16, DN and AH clear; RMode 0. x86-64: MXCSR 0x1f80, the default).
static void fpu_init(void) {
#if defined(__aarch64__)
    uint64_t was;
    __asm__ volatile("mrs %0, fpcr" : "=r"(was));
    uint64_t want = was & ~((1ull << 24) | (1ull << 25) | (1ull << 19) | (1ull << 1) | (3ull << 22));
    __asm__ volatile("msr fpcr, %0" : : "r"(want));
    trace_line("fpcr 0x%llx -> 0x%llx", (unsigned long long)was, (unsigned long long)want);
#elif defined(__x86_64__)
    unsigned was, want = 0x1f80;
    __asm__ volatile("stmxcsr %0" : "=m"(was));
    __asm__ volatile("ldmxcsr %0" : : "m"(want));
    trace_line("mxcsr 0x%04x -> 0x%04x", was, want);
#endif
}

// The entry: main() of the host's C runtime (the native link names this object's main as the image's entry).
int main(int argc, char** argv) {
    (void)argc; (void)argv;
    const char* path = getenv("HULK_TRACE_FILE");
    g_trace = fopen(path && *path ? path : "hulk-startup-trace.txt", "w");
    hulk_xdk_first_call_sink = first_call;
    install_crash_handler();
    fpu_init();
    trace_line("xbe-window none (native build: data is named, never mapped at XBE addresses)");
#if defined(__linux__)
    trace_line("low-4gb reserved %u MB", g_low_reserved_mb);
#endif
    if (hulk_u32 hang = env_u32("HULK_HANG", 0)) {
        pthread_t th;
        pthread_create(&th, 0, watchdog, (void*)(uintptr_t)hang);
        pthread_detach(th);
    }
    trace_line("start initializers=%u", hulk_game_initializer_count);
    static char phase[32];   // (static: a smashed stack must not take the crash report's phase with it)
    for (hulk_u32 i = 0; i < hulk_game_initializer_count; i++) {
        snprintf(phase, sizeof(phase), "init %u 0x%08x", i, hulk_game_initializer_addrs[i]);
        g_phase = phase;
        if (hulk_game_initializers[i]) {
            trace_line("init %u 0x%08x", i, hulk_game_initializer_addrs[i]);
            hulk_game_initializers[i]();
        } else {
            trace_line("skip %u 0x%08x (a library initializer, or no definition in the image)", i,
                       hulk_game_initializer_addrs[i]);
        }
    }
    trace_line("initializers done");
    hulk_replay_startup();
    g_phase = "main";
    int r = hulk_game_main();
    g_phase = "exit";
    trace_line("main returned %d", r);
    hulk_crt_run_atexit();
    summary("returned", (hulk_u32)r);
    return 0;
}
#endif

// The native image's entry point and start-up trace (docs/native-build.md "Start-up").
//
// What the Xbox start-up does before the game's main, done our way: the XBE's entry is XAPI's (library code, not
// in the tree); after its own set-up it runs the C initializers, then the C++ dynamic initializers listed between
// the `.CRT$XCA` and `.CRT$XCZ` markers (the game's `.text$yc` functions, each constructing a global and
// registering its destructor with atexit), then calls main. The native image runs the same game initializers, in
// the XBE's order, through the tree's definitions of them (tools/native_link.py writes the table:
// build/native/link/startup.s), skips the library ones (D3D, DSOUND, XGRAPHICS, XPP and LIBCMT initializers: those
// libraries are the shim here), and calls the tree's main (`hulk_game_main`, aliased by native_link.py).
//
// The trace (HULK_TRACE_FILE, default hulk-startup-trace.txt): every step of the start-up, the first call of every
// stand-in with its caller (xdk_shim.h), and how the run ended (main returned, a call to a function the image still
// lacks, or a crash with the registers and the frame-pointer chain). tools/native_run.py runs the image under Wine
// and turns the addresses into the tree's symbols and XBE addresses.
#include "xdk_shim.h"
#include "../crt/host_crt.h"

extern "C" {
// build/native/link/startup.s (tools/native_link.py)
typedef void(HULK_CDECL* hulk_init_fn)(void);
extern hulk_init_fn hulk_game_initializers[];
extern const hulk_u32 hulk_game_initializer_addrs[];
extern const hulk_u32 hulk_game_initializer_count;
int HULK_CDECL hulk_game_main(void);
void HULK_CDECL hulk_replay_startup(void);  // replay_hooks.cpp (native10: a replay's tweaks before main)
extern hulk_init_fn hulk_clang_xc_a[], hulk_clang_xc_z[];  // clang's own .CRT$XCU entries lie between
void HULK_CDECL hulk_crt_run_atexit(void);
}

static hulk_host_file* hulk_trace_;
static const char* hulk_phase_ = "start";
static hulk_u32 hulk_seq_;

static void hulk_trace_line(const char* fmt, ...);

// The graphics backend's log (src/platform/sdl/pddi/win32_platform.cpp): one trace line "gfx <line>" per call.
extern "C" void HULK_CDECL hulk_native_log(const char* line) {
    char buf[480];
    int n = 0;
    while (line[n] && line[n] != '\n' && n < (int)sizeof(buf) - 1) {
        buf[n] = line[n];
        n++;
    }
    buf[n] = 0;
    hulk_trace_line("gfx %s", buf);
}

static void hulk_trace_line(const char* fmt, ...) {
    char buf[512];
    __builtin_va_list ap;
    __builtin_va_start(ap, fmt);
    int n = hulk_host__vsnprintf(buf, sizeof(buf) - 2, fmt, (char*)ap);
    __builtin_va_end(ap);
    if (n < 0 || n > (int)sizeof(buf) - 2)
        n = sizeof(buf) - 2;
    buf[n] = '\n';
    buf[n + 1] = 0;
    if (hulk_trace_) {
        hulk_host_fputs(buf, hulk_trace_);
        hulk_host_fflush(hulk_trace_);
    }
}

static void hulk_first_call(const char* name, const void* caller) {
    hulk_trace_line("first %u %s caller=0x%08x phase=%s", ++hulk_seq_, name, (hulk_u32)caller, hulk_phase_);
}

static void hulk_frames(hulk_u32 ebp) {
    // the frame-pointer chain (the tree is compiled with frame pointers: -O0), within 1 MB of the first frame;
    // HULK_FRAME_LOCALS=1: also the 8 words below each frame pointer (clang -O0 keeps `this` and the arguments there)
    hulk_u32 first = ebp;
    const char* locals = hulk_host_getenv("HULK_FRAME_LOCALS");
    for (int i = 0; i < 24 && ebp >= 0x10000 && (ebp & 3) == 0 && ebp - first < 0x100000; i++) {
        hulk_u32* f = (hulk_u32*)ebp;
        hulk_trace_line("frame %d ret=0x%08x", i, f[1]);
        if (locals)
            hulk_trace_line("locals %d ebp-0x20 0x%08x 0x%08x 0x%08x 0x%08x 0x%08x 0x%08x 0x%08x 0x%08x", i, f[-8], f[-7],
                            f[-6], f[-5], f[-4], f[-3], f[-2], f[-1]);
        if (f[0] <= ebp)
            break;
        ebp = f[0];
    }
}

static void hulk_summary(const char* how, hulk_u32 code) {
    const char* names[1024];
    hulk_u32 calls[1024];
    hulk_u32 n = hulk_xdk_called(names, calls, 1024);
    hulk_trace_line("end %s code=%u phase=%s imports_called=%u", how, code, hulk_phase_, n);
    for (hulk_u32 i = 0; i < n && i < 1024; i++)
        hulk_trace_line("called %s %u", names[i], calls[i]);
    if (hulk_trace_)
        hulk_host_fclose(hulk_trace_);
    hulk_trace_ = 0;
}

// A call to a symbol the image still lacks (tools/native_link.py's stub object: `push "name"; call this`).
extern "C" void HULK_CDECL hulk_native_missing(const char* name) {
    // our frame: [ebp+4] returns into the stub, [ebp+8] is name, [ebp+12] the stub's caller's return address
    const hulk_u32* fp = (const hulk_u32*)__builtin_frame_address(0);
    hulk_trace_line("missing %s caller=0x%08x phase=%s", name, fp[3], hulk_phase_);
    hulk_frames((hulk_u32)__builtin_frame_address(0));
    hulk_summary("missing", 3);
    hulk_host_ExitProcess(3);
}

// Windows' EXCEPTION_POINTERS / EXCEPTION_RECORD / x86 CONTEXT, as far as the report needs them (public layouts).
struct hulk_exception_record { hulk_u32 code, flags, record, address, nparams, info[15]; };
struct hulk_exception_pointers { hulk_exception_record* record; unsigned char* context; };

static void hulk_peek(const char* peek);

static hulk_u32 HULK_STDCALL hulk_crash_filter(hulk_exception_pointers* ep) {
    static int busy;
    if (busy++)
        hulk_host_ExitProcess(5);
    const hulk_u32* c = (const hulk_u32*)ep->context;
    hulk_trace_line("crash code=0x%08x address=0x%08x info=0x%08x,0x%08x phase=%s", ep->record->code,
                    ep->record->address, ep->record->nparams > 0 ? ep->record->info[0] : 0,
                    ep->record->nparams > 1 ? ep->record->info[1] : 0, hulk_phase_);
    // CONTEXT (x86): Edi 0x9c, Esi 0xa0, Ebx 0xa4, Edx 0xa8, Ecx 0xac, Eax 0xb0, Ebp 0xb4, Eip 0xb8, Esp 0xc4
    hulk_trace_line("regs eip=0x%08x esp=0x%08x ebp=0x%08x eax=0x%08x ebx=0x%08x ecx=0x%08x edx=0x%08x "
                    "esi=0x%08x edi=0x%08x", c[0xb8 / 4], c[0xc4 / 4], c[0xb4 / 4], c[0xb0 / 4], c[0xa4 / 4],
                    c[0xac / 4], c[0xa8 / 4], c[0xa0 / 4], c[0x9c / 4]);
    hulk_u32 esp = c[0xc4 / 4];
    if (esp >= 0x10000)
        hulk_trace_line("stack0 0x%08x 0x%08x 0x%08x 0x%08x", ((hulk_u32*)esp)[0], ((hulk_u32*)esp)[1],
                        ((hulk_u32*)esp)[2], ((hulk_u32*)esp)[3]);
    hulk_frames(c[0xb4 / 4]);
    // when the frame chain is broken: the words near the stack top that look like return addresses into the image
    if (esp >= 0x10000) {
        int shown = 0;
        // (HULK_CRASH_BELOW=n: start n words below esp: the stale frames of the calls that just returned)
        const char* below = hulk_host_getenv("HULK_CRASH_BELOW");
        int from = 0;
        if (below)
            for (; *below >= '0' && *below <= '9'; below++)
                from = from * 10 + (*below - '0');
        for (int i = -from; i < 256 && shown < 48; i++) {
            hulk_u32 v = ((hulk_u32*)esp)[i];
            if (v >= 0x10001000u && v < 0x10900000u) {
                hulk_trace_line("scan esp%c0x%03x 0x%08x", i < 0 ? '-' : '+', (i < 0 ? -i : i) * 4, v);
                shown++;
            }
        }
    }
    // HULK_CRASH_DUMP=1: the 0x40 bytes at each register that points into the heap or the image (last: a bad
    // pointer faults again and ends the process with code 5)
    if (hulk_host_getenv("HULK_CRASH_DUMP")) {
        static const int regs[] = {0xb0, 0xa4, 0xac, 0xa8, 0xa0, 0x9c, 0xb4};
        static const char* const names[] = {"eax", "ebx", "ecx", "edx", "esi", "edi", "ebp"};
        if (hulk_trace_)
            hulk_host_fflush(hulk_trace_);
        for (int r = 0; r < 7; r++) {
            hulk_u32 v = c[regs[r] / 4] & ~3u;
            if (v < 0x00100000u)
                continue;
            const hulk_u32* m = (const hulk_u32*)v;
            for (int k = 0; k < 16; k += 8)
                hulk_trace_line("dump %s+0x%02x 0x%08x 0x%08x 0x%08x 0x%08x 0x%08x 0x%08x 0x%08x 0x%08x", names[r],
                                k * 4, m[k], m[k + 1], m[k + 2], m[k + 3], m[k + 4], m[k + 5], m[k + 6], m[k + 7]);
        }
    }
    // HULK_CRASH_PEEK=addr[,addr...]: the same for addresses from an earlier run's dump (heap layouts repeat)
    if (const char* peek = hulk_host_getenv("HULK_CRASH_PEEK"))
        hulk_peek(peek);
    hulk_summary("crash", ep->record->code);
    hulk_host_ExitProcess(4);
    return 0;
}

static void hulk_peek(const char* peek) {
    {
        while (*peek) {
            hulk_u32 v = 0;
            if (peek[0] == '0' && (peek[1] == 'x' || peek[1] == 'X'))
                peek += 2;
            for (; *peek && *peek != ','; peek++)
                v = v * 16 + (hulk_u32)(*peek <= '9' ? *peek - '0' : (*peek | 0x20) - 'a' + 10);
            if (*peek == ',')
                peek++;
            const hulk_u32* m = (const hulk_u32*)(v & ~3u);
            for (int k = 0; k < 16; k += 8)
                hulk_trace_line("peek 0x%08x+0x%02x 0x%08x 0x%08x 0x%08x 0x%08x 0x%08x 0x%08x 0x%08x 0x%08x", v,
                                k * 4, m[k], m[k + 1], m[k + 2], m[k + 3], m[k + 4], m[k + 5], m[k + 6], m[k + 7]);
        }
    }
}

// tools/native_link.py HULK_TRACE_FUNCS probe wrappers: one `fcall` line per call (frame: saved eax, ecx, edx, the
// return address, the stack arguments), at most HULK_TRACE_MAX (default 64) per function.
// native13: GameClock::Update calls so far (replay_hooks.cpp's hulk_native_frame counts them; 0 without --gfx), in
// the probes' `fcall` lines as f=N (the frame the checkpoints and the hybrid's trace sessions number)
extern "C" hulk_u32 hulk_native_frame_no;
hulk_u32 hulk_native_frame_no;

#ifdef HULK_UBSAN_FLOAT
// ubsan1 (docs/native-float.md "float-cast-overflow"): the game's TUs built with HULK_NATIVE_SANITIZE=float-cast call
// this for every float -> integer conversion whose value does not fit (the original's __ftol2 wraps it, x87 fistp and
// SSE give 0x80000000). One `ubsan` trace line per site at its 1st, 2nd, 4th, 8th ... hit; the run goes on (the
// conversion then gives what the native image always gave). Layouts: LLVM's ubsan_value.h (public ABI of -fsanitize).
struct hulk_ubsan_type { unsigned short kind, info; char name[1]; };
struct hulk_ubsan_data { const char* file; hulk_u32 line, col; const hulk_ubsan_type *from, *to; };
extern "C" void HULK_CDECL __ubsan_handle_float_cast_overflow(const hulk_ubsan_data* d, hulk_u32 v) {
    static const hulk_ubsan_data* site[4096];
    static hulk_u32 count[4096], first[4096];
    static volatile int lock;
    while (__atomic_exchange_n(&lock, 1, __ATOMIC_ACQUIRE))
        ;
    hulk_u32 h = (((hulk_u32)d >> 2) * 2654435761u) >> 20;
    while (site[h] && site[h] != d)
        h = (h + 1) & 4095;
    if (!site[h]) {
        site[h] = d;
        first[h] = hulk_native_frame_no;
    }
    hulk_u32 n = ++count[h];
    if (!(n & (n - 1))) {
        double x;
        hulk_u32 bits0, bits1 = 0;
        if (d->from->info <= 32) {
            float f;
            __builtin_memcpy(&f, &v, 4);
            x = f;
            bits0 = v;
        } else {
            const hulk_u32* p = (const hulk_u32*)v;
            __builtin_memcpy(&x, p, 8);
            bits0 = p[0];
            bits1 = p[1];
        }
        hulk_trace_line("ubsan float-cast site=0x%08x ret=0x%08x file=%s line=%u col=%u from=%s to=%s count=%u first_frame=%u "
                        "frame=%u bits=%08x%08x value=%g",
                        (hulk_u32)d, (hulk_u32)__builtin_return_address(0), d->file, d->line, d->col, d->from->name,
                        d->to->name, n, first[h], hulk_native_frame_no, bits1, bits0, x);
    }
    __atomic_store_n(&lock, 0, __ATOMIC_RELEASE);
}
#endif

static int trace_func_impl(hulk_u32 addr, const hulk_u32* f) {
    static hulk_u32 seen_addr[64], seen_n[64];
    static hulk_u32 limit = 0;
    if (!limit) {
        const char* v = hulk_host_getenv("HULK_TRACE_MAX");
        limit = 64;
        if (v && *v) {
            limit = 0;
            for (; *v >= '0' && *v <= '9'; v++)
                limit = limit * 10 + (hulk_u32)(*v - '0');
        }
    }
    // native14: HULK_TRACE_WATCH=<pointer hex>:<offset hex> (or =<address hex>): the 3 words at (*pointer + offset) (a singleton's
    // field), compared at every probe call: a change is logged with this probe and the previous one (the write
    // happened between them), from HULK_TRACE_FROM on
    static const char* watch = (const char*)1;
    static hulk_u32 w_ptr, w_off, w_old[3], w_prev, w_abs;
    if (watch == (const char*)1) {
        watch = hulk_host_getenv("HULK_TRACE_WATCH");
        if (watch && *watch == '=') {     // `=<hex>`: an absolute address (no pointer to read first)
            w_abs = 1;
            watch++;
        }
        hulk_u32* acc = &w_ptr;
        for (const char* q = watch; q && *q; q++) {
            if (*q == ':')
                acc = &w_off;
            else
                *acc = *acc * 16 + (hulk_u32)(*q <= '9' ? *q - '0' : (*q | 0x20) - 'a' + 10);
        }
    }
    if (w_ptr) {
        hulk_u32 obj = w_abs ? w_ptr : *(const hulk_u32*)w_ptr, wmb[7] = {0};
        // native16: an absolute address may not be mapped yet (heap not grown that far)
        if (obj && (hulk_host_VirtualQuery((const void*)(obj + w_off), wmb, sizeof(wmb)) != sizeof(wmb) || wmb[4] != 0x1000 ||
                    (wmb[5] & 0x101) || obj + w_off + 12 > wmb[0] + wmb[3]))
            obj = 0;
        if (obj) {
            const hulk_u32* m = (const hulk_u32*)(obj + w_off);
            if (m[0] != w_old[0] || m[1] != w_old[1] || m[2] != w_old[2]) {
                if (w_prev)
                    hulk_trace_line("watch f=%u between 0x%08x and 0x%08x (ret=0x%08x): %08x %08x %08x -> %08x %08x %08x",
                                    hulk_native_frame_no, w_prev, addr, f[3], w_old[0], w_old[1], w_old[2], m[0], m[1], m[2]);
                w_old[0] = m[0]; w_old[1] = m[1]; w_old[2] = m[2];
            }
        }
        w_prev = addr;
    }
    // native14: HULK_TRACE_FROM=<frame>: log nothing before that GameClock frame (the per-function limit counts from it)
    static hulk_u32 from = 0xffffffffu;
    if (from == 0xffffffffu) {
        const char* v = hulk_host_getenv("HULK_TRACE_FROM");
        from = 0;
        for (; v && *v >= '0' && *v <= '9'; v++)
            from = from * 10 + (hulk_u32)(*v - '0');
    }
    if (hulk_native_frame_no < from)
        return 0;
    int k = 0;
    while (k < 64 && seen_addr[k] && seen_addr[k] != addr)
        k++;
    if (k < 64) {
        seen_addr[k] = addr;
        if (seen_n[k]++ >= limit)
            return 0;
    }
    hulk_trace_line("fcall 0x%08x ecx=0x%08x edx=0x%08x ret=0x%08x args 0x%08x 0x%08x 0x%08x 0x%08x tid=%u f=%u", addr, f[1],
                    f[2], f[3], f[4], f[5], f[6], f[7], hulk_host_GetCurrentThreadId(), hulk_native_frame_no);
    // native16: HULK_TRACE_SPAN=[<hex function>/]<slot 0-8>+<hex offset>[@+<hex offset>...]:<hex words>[,...]: that many
    // words at (slot value + offset) (an array inside an object: a manager's entry table), 8 per line, when committed
    // memory; `@` reads the word at the address so far (a pointer field) and goes on from there; a `<function>/` prefix
    // limits a spec to that probed function (several specs: comma-separated)
    static const char* span = (const char*)1;
    if (span == (const char*)1)
        span = hulk_host_getenv("HULK_TRACE_SPAN");
    for (const char* sp = span; sp && *sp;) {
        const char* q = sp;
        hulk_u32 only = 0;
        for (const char* r = sp; *r && *r != ','; r++)
            if (*r == '/') {
                for (; q < r; q++)
                    only = only * 16 + (hulk_u32)(*q <= '9' ? *q - '0' : (*q | 0x20) - 'a' + 10);
                q = r + 1;
                break;
            }
        const char* end = q;
        while (*end && *end != ',')
            end++;
        sp = *end ? end + 1 : end;
        if ((only && only != addr) || *q < '0' || *q > '8')
            continue;
        hulk_u32 base = *q == '0' ? f[1] : f[3 + (*q - '0')], off = 0, n = 0, *acc = &off;
        for (q++; q < end; q++) {
            if (*q == '+')
                continue;
            if (*q == '@') {
                hulk_u32 at0 = base + off, mb[7] = {0};
                if (at0 < 0x10000 || hulk_host_VirtualQuery((const void*)at0, mb, sizeof(mb)) != sizeof(mb) || mb[4] != 0x1000 ||
                    (mb[5] & 0x101)) {
                    base = 0;
                    break;
                }
                base = *(const hulk_u32*)at0;
                off = 0;
                continue;
            }
            if (*q == ':') {
                acc = &n;
                continue;
            }
            *acc = *acc * 16 + (hulk_u32)(*q <= '9' ? *q - '0' : (*q | 0x20) - 'a' + 10);
        }
        hulk_u32 at = base + off, mbi[7] = {0};
        n = (n + 7) & ~7u;
        if (n > 0x4000)
            n = 0x4000;
        if (at >= 0x10000 && hulk_host_VirtualQuery((const void*)at, mbi, sizeof(mbi)) == sizeof(mbi) && mbi[4] == 0x1000 &&
            !(mbi[5] & 0x101) && at + 4 * n <= mbi[0] + mbi[3]) {
            const hulk_u32* m = (const hulk_u32*)at;
            for (hulk_u32 k = 0; k < n; k += 8)
                hulk_trace_line("  span +0x%04x: %08x %08x %08x %08x %08x %08x %08x %08x", k * 4, m[k], m[k + 1], m[k + 2],
                                m[k + 3], m[k + 4], m[k + 5], m[k + 6], m[k + 7]);
        }
    }
    // native12: HULK_TRACE_STR=<digits 1-8>: the NUL-terminated string (up to 96 chars) each of these stack arguments
    // points at, when committed memory (varargs too: `5` is luaG_runerror's name)
    static const char* strs = (const char*)1;
    if (strs == (const char*)1)
        strs = hulk_host_getenv("HULK_TRACE_STR");
    for (const char* d = strs; d && *d >= '1' && *d <= '8'; d++) {
        hulk_u32 v = f[3 + (*d - '0')];
        hulk_u32 mbi[7] = {0};
        if (v < 0x10000 || hulk_host_VirtualQuery((const void*)v, mbi, sizeof(mbi)) < sizeof(mbi) || mbi[4] != 0x1000 ||
            (mbi[5] & 0x101))
            continue;
        char buf[100];
        int n = 0;
        while (n < 96 && v + n < mbi[0] + mbi[3] && ((const char*)v)[n]) {
            char c = ((const char*)v)[n];
            buf[n++] = c >= 32 && c < 127 ? c : '?';
        }
        buf[n] = 0;
        hulk_trace_line("  str %c 0x%08x: \"%s\"", *d, v, buf);
    }
    // native12: HULK_TRACE_PATH=<slot><+|-hex>...: follow a pointer chain from a slot (0 ecx, 1-8 the stack
    // arguments): each step reads the word at (current + offset); logs every value, then the final object's first
    // 8 words and the string at +0x10 (a Lua TString: `1+14+0-4+c+20` is the running closure's chunk name)
    static const char* path = (const char*)1;
    if (path == (const char*)1)
        path = hulk_host_getenv("HULK_TRACE_PATH");
    for (const char* pp = path; pp && ((*pp >= '0' && *pp <= '8') || *pp == '@');) {  // (several: comma-separated)
        hulk_u32 cur = *pp == '0' ? f[1] : f[3 + (*pp - '0')];
        const char* q = pp + 1;
        if (*pp == '@') {       // `@<hex>`: an absolute address (a global of the image, from the map)
            cur = 0;
            for (; (*q >= '0' && *q <= '9') || ((*q | 0x20) >= 'a' && (*q | 0x20) <= 'f'); q++)
                cur = cur * 16 + (hulk_u32)(*q <= '9' ? *q - '0' : (*q | 0x20) - 'a' + 10);
        }
        char line[300];
        int ln = hulk_host__snprintf(line, sizeof(line), "  path %c=0x%08x", *pp, cur);
        int ok = 1;
        while (ok && (*q == '+' || *q == '-')) {
            int neg = *q == '-';
            hulk_u32 off = 0;
            for (q++; (*q >= '0' && *q <= '9') || ((*q | 0x20) >= 'a' && (*q | 0x20) <= 'f'); q++)
                off = off * 16 + (hulk_u32)(*q <= '9' ? *q - '0' : (*q | 0x20) - 'a' + 10);
            hulk_u32 at = neg ? cur - off : cur + off;
            hulk_u32 mbi[7] = {0};
            if (at < 0x10000 || hulk_host_VirtualQuery((const void*)at, mbi, sizeof(mbi)) < sizeof(mbi) ||
                mbi[4] != 0x1000 || (mbi[5] & 0x101)) {
                ok = 0;
                break;
            }
            cur = *(const hulk_u32*)at;
            if (ln > 0 && ln < (int)sizeof(line) - 16)
                ln += hulk_host__snprintf(line + ln, sizeof(line) - ln, " -> 0x%08x", cur);
        }
        hulk_trace_line("%s%s", line, ok ? "" : " (unreadable)");
        hulk_u32 mbi[7] = {0};
        if (ok && cur >= 0x10000 && hulk_host_VirtualQuery((const void*)cur, mbi, sizeof(mbi)) == sizeof(mbi) &&
            mbi[4] == 0x1000 && !(mbi[5] & 0x101) && cur + 0x70 <= mbi[0] + mbi[3]) {
            const hulk_u32* m = (const hulk_u32*)cur;
            char sb[100];
            int n = 0;
            while (n < 96 && ((const char*)cur)[0x10 + n]) {
                char c = ((const char*)cur)[0x10 + n];
                sb[n++] = c >= 32 && c < 127 ? c : '?';
            }
            sb[n] = 0;
            hulk_trace_line("  path end: 0x%08x 0x%08x 0x%08x 0x%08x 0x%08x 0x%08x 0x%08x 0x%08x \"%s\"", m[0], m[1],
                            m[2], m[3], m[4], m[5], m[6], m[7], sb);
        }
        while (*q && *q != ',')
            q++;
        pp = *q == ',' ? q + 1 : q;
    }
    // native10: HULK_TRACE_DEREF=<digits>: also 8 words at the pointers in these slots (0 ecx, 1-4 the stack
    // arguments), each when committed memory (VirtualQuery), and 8 words at the first word of each (a vptr-led
    // object: the object's class and its fields; a pointer to a pointer: the pointee)
    static const char* deref = (const char*)1;
    if (deref == (const char*)1)
        deref = hulk_host_getenv("HULK_TRACE_DEREF");
    // HULK_TRACE_LIST=<slot>+<hex offset>: the linked list whose head pointer lies at that offset of the slot's
    // object (`0+8`: ecx's +8): up to 400 nodes, `next` at +4; each node's words 0, 2, 3, 4, 5 (a vptr-led node)
    static const char* list = (const char*)1;
    if (list == (const char*)1)
        list = hulk_host_getenv("HULK_TRACE_LIST");
    if (list && *list >= '0' && *list <= '4' && list[1] == '+') {
        hulk_u32 off = 0;
        for (const char* q = list + 2; *q; q++)
            off = off * 16 + (hulk_u32)(*q <= '9' ? *q - '0' : (*q | 0x20) - 'a' + 10);
        hulk_u32 base = *list == '0' ? f[1] : f[3 + (*list - '0')];
        hulk_u32 mbi[7] = {0};
        if (base >= 0x10000 && hulk_host_VirtualQuery((const void*)base, mbi, sizeof(mbi)) == sizeof(mbi) && mbi[4] == 0x1000) {
            hulk_u32 n = *(const hulk_u32*)(base + off);
            for (int i = 0; i < 400 && n >= 0x10000; i++) {
                if (hulk_host_VirtualQuery((const void*)n, mbi, sizeof(mbi)) != sizeof(mbi) || mbi[4] != 0x1000)
                    break;
                const hulk_u32* m = (const hulk_u32*)n;
                hulk_trace_line("  node %d 0x%08x: 0x%08x 0x%08x 0x%08x 0x%08x 0x%08x", i, n, m[0], m[2], m[3], m[4], m[5]);
                n = m[1];
            }
        }
    }
    for (const char* d = deref; d && *d >= '0' && *d <= '4'; d++) {
        hulk_u32 v = *d == '0' ? f[1] : f[3 + (*d - '0')];
        for (int depth = 0; depth < 2 && v >= 0x10000; depth++) {
            hulk_u32 mbi[7] = {0};
            if (hulk_host_VirtualQuery((const void*)v, mbi, sizeof(mbi)) < sizeof(mbi) || mbi[4] != 0x1000 /* MEM_COMMIT */ ||
                (mbi[5] & 0x101) || v + 32 > mbi[0] + mbi[3])
                break;
            const hulk_u32* m = (const hulk_u32*)v;
            hulk_trace_line("  deref %c%s 0x%08x: 0x%08x 0x%08x 0x%08x 0x%08x 0x%08x 0x%08x 0x%08x 0x%08x", *d,
                            depth ? "*" : "", v, m[0], m[1], m[2], m[3], m[4], m[5], m[6], m[7]);
            // native12: HULK_TRACE_WIDE=1: the object's next 8 words too (fields at +0x20..+0x3c)
            static const char* wide = (const char*)1;
            if (wide == (const char*)1)
                wide = hulk_host_getenv("HULK_TRACE_WIDE");
            if (wide && *wide == '1' && !depth && v + 64 <= mbi[0] + mbi[3])
                hulk_trace_line("  deref %c+20 0x%08x: 0x%08x 0x%08x 0x%08x 0x%08x 0x%08x 0x%08x 0x%08x 0x%08x", *d, v + 32,
                                m[8], m[9], m[10], m[11], m[12], m[13], m[14], m[15]);
            v = m[0];
        }
    }
    return 1;
}

extern "C" void HULK_CDECL hulk_trace_func(hulk_u32 addr, const hulk_u32* f) {
    trace_func_impl(addr, f);
}

// native14: HULK_TRACE_EXIT probes (tools/native_link.py): the wrapper logs the entry as HULK_TRACE_FUNCS does, then
// returns through _hulk_tx_ret, which logs `fexit` (eax, edx, st0 when the x87 stack holds a result) and, with
// HULK_TRACE_XDEREF=<digits 0-4, r>, 16 words at those entry arguments (0: ecx; r: the returned eax) (output buffers) after the call. The
// real return addresses wait on a small stack (per thread id, spin-locked: diagnostics only).
struct HulkTxFrame {
    hulk_u32 tid, addr, ret, logged, args[5];   // args[0]: ecx at entry, 1-4: the stack arguments
};
static HulkTxFrame hulk_tx_stack[1024];
static int hulk_tx_top;
static volatile int hulk_tx_lock;

extern "C" void HULK_CDECL hulk_trace_enter(hulk_u32 addr, const hulk_u32* f) {
    int logged = trace_func_impl(addr, f);
    while (__sync_lock_test_and_set(&hulk_tx_lock, 1))
        ;
    if (hulk_tx_top < 1024) {
        HulkTxFrame& t = hulk_tx_stack[hulk_tx_top++];
        t.tid = hulk_host_GetCurrentThreadId();
        t.addr = addr;
        t.ret = f[3];
        t.logged = (hulk_u32)logged;
        t.args[0] = f[1];
        for (int i = 0; i < 4; i++)
            t.args[1 + i] = f[4 + i];
    }
    __sync_lock_release(&hulk_tx_lock);
}

extern "C" hulk_u32 HULK_CDECL hulk_trace_exit(const hulk_u32* regs, const double* st0, int has_st0) {
    hulk_u32 tid = hulk_host_GetCurrentThreadId();
    HulkTxFrame t = {0, 0, 0, 0, {0, 0, 0, 0, 0}};
    while (__sync_lock_test_and_set(&hulk_tx_lock, 1))
        ;
    for (int k = hulk_tx_top - 1; k >= 0; k--) {
        if (hulk_tx_stack[k].tid == tid) {
            t = hulk_tx_stack[k];
            for (int j = k; j + 1 < hulk_tx_top; j++)
                hulk_tx_stack[j] = hulk_tx_stack[j + 1];
            hulk_tx_top--;
            break;
        }
    }
    __sync_lock_release(&hulk_tx_lock);
    if (t.logged) {
        const hulk_u32* d = (const hulk_u32*)st0;
        if (has_st0)
            hulk_trace_line("fexit 0x%08x eax=0x%08x edx=0x%08x st0=%08x%08x tid=%u f=%u", t.addr, regs[0], regs[2], d[1],
                            d[0], tid, hulk_native_frame_no);
        else
            hulk_trace_line("fexit 0x%08x eax=0x%08x edx=0x%08x tid=%u f=%u", t.addr, regs[0], regs[2], tid,
                            hulk_native_frame_no);
        static const char* xd = (const char*)1;
        if (xd == (const char*)1)
            xd = hulk_host_getenv("HULK_TRACE_XDEREF");
        for (const char* q = xd; q && ((*q >= '0' && *q <= '4') || *q == 'r'); q++) {
            hulk_u32 v = *q == 'r' ? regs[0] : t.args[*q - '0'];   // `r`: the returned eax
            hulk_u32 mbi[7] = {0};
            if (v < 0x10000 || hulk_host_VirtualQuery((const void*)v, mbi, sizeof(mbi)) < sizeof(mbi) || mbi[4] != 0x1000 ||
                (mbi[5] & 0x101) || v + 64 > mbi[0] + mbi[3])
                continue;
            const hulk_u32* m = (const hulk_u32*)v;
            for (int k = 0; k < 16; k += 8)
                hulk_trace_line("  xderef %c 0x%08x+0x%02x: %08x %08x %08x %08x %08x %08x %08x %08x", *q, v, k * 4, m[k],
                                m[k + 1], m[k + 2], m[k + 3], m[k + 4], m[k + 5], m[k + 6], m[k + 7]);
        }
    }
    return t.ret;
}

// HULK_HANG=n (seconds): a watchdog thread that, n seconds into the run, samples the main thread (its current fiber)
// HULK_HANG_SAMPLES times (default 4, 250 ms apart): registers, frame chain and stack scan as for a crash, then
// ends the run (summary "hang"). For runs that stop making progress without crashing.
static hulk_u32 hulk_main_tid_;

static hulk_u32 hulk_env_u32(const char* name, hulk_u32 dflt) {
    const char* v = hulk_host_getenv(name);
    if (!v || !*v)
        return dflt;
    hulk_u32 n = 0;
    for (; *v >= '0' && *v <= '9'; v++)
        n = n * 10 + (hulk_u32)(*v - '0');
    return n;
}

extern "C" hulk_u32 hulk_xdk_game_tids[8], hulk_xdk_game_ntids;  // threads.cpp: the game's own threads

static hulk_u32 HULK_STDCALL hulk_watchdog(void* arg) {
    hulk_host_Sleep((hulk_u32)arg * 1000);
    hulk_u32 samples = hulk_env_u32("HULK_HANG_SAMPLES", 4);
    static hulk_u32 ctx[0x2cc / 4 + 4];
    for (hulk_u32 s = 0; s < samples; s++)
      for (hulk_u32 t = 0; t <= hulk_xdk_game_ntids && t < 9; t++) {
        hulk_u32 tid = t ? hulk_xdk_game_tids[t - 1] : hulk_main_tid_;
        void* h = hulk_host_OpenThread(0x1fffff /* THREAD_ALL_ACCESS */, 0, tid);
        if (!h)
            continue;
        hulk_host_SuspendThread(h);
        ctx[0] = 0x10007;  // CONTEXT_i386 | CONTROL | INTEGER | SEGMENTS
        if (hulk_host_GetThreadContext(h, ctx)) {
            const hulk_u32* c = ctx;
            hulk_trace_line("hang sample %u thread %u%s phase=%s", s, t, t ? " (game)" : " (main)", hulk_phase_);
            hulk_trace_line("regs eip=0x%08x esp=0x%08x ebp=0x%08x eax=0x%08x ebx=0x%08x ecx=0x%08x edx=0x%08x "
                            "esi=0x%08x edi=0x%08x", c[0xb8 / 4], c[0xc4 / 4], c[0xb4 / 4], c[0xb0 / 4], c[0xa4 / 4],
                            c[0xac / 4], c[0xa8 / 4], c[0xa0 / 4], c[0x9c / 4]);
            hulk_frames(c[0xb4 / 4]);
            hulk_u32 esp = c[0xc4 / 4];
            int shown = 0;
            hulk_u32 mbi[7] = {0};  // MEMORY_BASIC_INFORMATION: base, allocation base, protect, size, ...
            hulk_u32 top = esp;
            if (esp >= 0x10000 && hulk_host_VirtualQuery((const void*)esp, mbi, sizeof(mbi)))
                top = mbi[0] + mbi[3];
            for (int i = 0; esp >= 0x10000 && esp + i * 4 + 4 <= top && i < 256 && shown < 24; i++) {
                hulk_u32 v = ((hulk_u32*)esp)[i];
                if (v >= 0x10001000u && v < 0x10900000u) {
                    hulk_trace_line("scan esp+0x%03x 0x%08x", i * 4, v);
                    shown++;
                }
            }
        }
        hulk_host_ResumeThread(h);
        hulk_host_CloseHandle(h);
        if (t == hulk_xdk_game_ntids)
            hulk_host_Sleep(250);
    }
    if (const char* peek = hulk_host_getenv("HULK_CRASH_PEEK"))
        hulk_peek(peek);
    hulk_summary("hang", 0);
    hulk_host_ExitProcess(6);
    return 0;
}

// The XBE's data at its own addresses. Verified sources pass XBE data addresses as integer literals: a string in
// .rdata (`FUN_0027b020((const char*)0x3f3fd8)`), and above all the RTTI type descriptors of every dynamic_cast
// (`__RTDynamicCast(p, 0, (void*)0x491ca8, (void*)0x492238, 0)`). MSVC 7.1 emits the same immediate whether the
// source names the item or casts its address, so the byte match can't tell them apart (docs/native-build.md,
// "Start-up": a source finding). Until those sources name their data, the image maps a copy of the XBE's data
// sections, read from the player's own default.xbe at run time, at their original addresses: constants (strings,
// RTTI descriptors, tables) then read right; a write there would not reach the tree's own copy of that item.
//
// The range must be free before the host's start-up puts its heaps there, so the image starts itself a second
// time, suspended, reserves the range in that process first and lets it run (HULK_NATIVE_CHILD marks the child).
static const hulk_u32 hulk_win_lo = 0x003f0000, hulk_win_hi = 0x0058a000;  // .rdata through $$XSIMAGE

static void hulk_run_child(void) {
    char exe[520];
    hulk_host_GetModuleFileNameA(0, exe, sizeof(exe));
    hulk_host_SetEnvironmentVariableA("HULK_NATIVE_CHILD", "1");
    hulk_u32 si[17] = {68};      // STARTUPINFOA: cb, the rest zero
    void* pi[4] = {0, 0, 0, 0};  // PROCESS_INFORMATION: process, thread, pid, tid
    if (!hulk_host_CreateProcessA(exe, hulk_host_GetCommandLineA(), 0, 0, 0, 4 /* CREATE_SUSPENDED */, 0, 0, si, pi)) {
        hulk_trace_line("xbe-window child: CreateProcess failed; running without the window");
        return;
    }
    void* r = hulk_host_VirtualAllocEx(pi[0], (void*)hulk_win_lo, hulk_win_hi - hulk_win_lo, 0x2000 /* reserve */, 4);
    if (r != (void*)hulk_win_lo)
        hulk_trace_line("xbe-window child: reserve failed (0x%08x)", (hulk_u32)r);
    if (hulk_trace_)
        hulk_host_fclose(hulk_trace_);  // the child appends to the same trace
    hulk_trace_ = 0;
    hulk_host_ResumeThread(pi[1]);
    hulk_host_WaitForSingleObject(pi[0], 0xffffffffu);
    hulk_u32 code = 1;
    hulk_host_GetExitCodeProcess(pi[0], &code);
    hulk_host_ExitProcess(code);
}

static void hulk_map_xbe_window(void) {
    char path[520];
    const char* dir = hulk_host_getenv("HULK_DATA_DIR");
    if (!dir || !*dir) {
        hulk_trace_line("xbe-window none (HULK_DATA_DIR not set)");
        return;
    }
    hulk_host__snprintf(path, sizeof(path), "%s\\default.xbe", dir);
    hulk_host_file* f = hulk_host_fopen(path, "rb");
    if (!f) {
        hulk_trace_line("xbe-window none (cannot open %s)", path);
        return;
    }
    // (commit what the parent reserved; reserve and commit when running without a parent)
    void* m = hulk_host_VirtualAlloc((void*)hulk_win_lo, hulk_win_hi - hulk_win_lo, 0x1000, 4);
    if (m != (void*)hulk_win_lo)
        m = hulk_host_VirtualAlloc((void*)hulk_win_lo, hulk_win_hi - hulk_win_lo, 0x3000, 4);
    if (m != (void*)hulk_win_lo) {
        hulk_trace_line("xbe-window none (VirtualAlloc 0x%08x -> 0x%08x)", hulk_win_lo, (hulk_u32)m);
        hulk_host_fclose(f);
        return;
    }
    // XBE header (public format, as documented by the Xbox homebrew projects): base address at 0x104, section count
    // and section header address at 0x11c; each 56-byte section header: flags, virtual address, virtual size, raw
    // address, raw size, name address.
    hulk_u32 hdr[0x200 / 4];
    hulk_host_fread(hdr, 1, sizeof(hdr), f);
    hulk_u32 base = hdr[0x104 / 4], nsec = hdr[0x11c / 4], sec = hdr[0x120 / 4];
    hulk_u32 copied = 0;
    for (hulk_u32 i = 0; i < nsec && i < 64; i++) {
        hulk_u32 sh[14];
        hulk_host_fseek(f, (long)(sec - base + i * 56), 0);
        hulk_host_fread(sh, 1, 56, f);
        hulk_u32 va = sh[1], raw = sh[3], rsize = sh[4];
        if (va < hulk_win_lo || va + rsize > hulk_win_hi)
            continue;
        hulk_host_fseek(f, (long)raw, 0);
        copied += hulk_host_fread((void*)va, 1, rsize, f);
    }
    hulk_host_fclose(f);
    hulk_trace_line("xbe-window 0x%08x-0x%08x bytes=%u", hulk_win_lo, hulk_win_hi, copied);
}

// The x87 control word the game runs with (docs/native-float.md): XAPI's _cinit calls the CRT's _fpmath(1), which
// sets 53-bit precision (_controlfp(_PC_53, _MCW_PC)); rounding to nearest, all exceptions masked: 0x027f. Windows
// and Wine start every thread with the same word, so this only pins it (and logs what the host gave us).
static void hulk_x87_init(void) {
#if defined(_M_IX86) || defined(__i386__)
    unsigned short was = 0, want = 0x027f;
    __asm__ volatile("fnstcw %0" : "=m"(was));
    __asm__ volatile("fnclex\n\tfldcw %0" : : "m"(want));
    hulk_trace_line("x87 control word 0x%04x -> 0x%04x", was, want);
#endif
}

extern "C" void HULK_CDECL hulk_native_entry(void) {
    const char* path = hulk_host_getenv("HULK_TRACE_FILE");
    const char* child = hulk_host_getenv("HULK_NATIVE_CHILD");
    hulk_trace_ = hulk_host_fopen(path && *path ? path : "hulk-startup-trace.txt", child ? "a" : "w");
    if (!child && !hulk_host_getenv("HULK_NO_WINDOW"))
        hulk_run_child();  // (returns only if the child could not be started)
    hulk_xdk_first_call_sink = hulk_first_call;
    hulk_host_SetUnhandledExceptionFilter((void*)hulk_crash_filter);
    hulk_map_xbe_window();
    hulk_main_tid_ = hulk_host_GetCurrentThreadId();
    hulk_x87_init();
    if (hulk_u32 hang = hulk_env_u32("HULK_HANG", 0))
        hulk_host_CreateThread(0, 0, (void*)hulk_watchdog, (void*)hang, 0, 0);
    hulk_trace_line("start initializers=%u", hulk_game_initializer_count);
    static char phase[32];  // (static: a smashed stack must not take the crash report's phase with it)
    // clang's own dynamic initializers: the isolated `.text$yc` sources define their global with its constructor
    // and are themselves the function that constructs it (the XBE's table below calls them), so these would
    // construct the same globals a second time. Counted, not run.
    hulk_u32 nclang = 0;
    for (hulk_init_fn* p = hulk_clang_xc_a + 1; p < hulk_clang_xc_z; p++)
        if (*p)
            nclang++;
    hulk_trace_line("clang initializers %u (not run: the XBE's table covers them)", nclang);
    for (hulk_u32 i = 0; i < hulk_game_initializer_count; i++) {
        hulk_host__snprintf(phase, sizeof(phase), "init %u 0x%08x", i, hulk_game_initializer_addrs[i]);
        hulk_phase_ = phase;
        if (hulk_game_initializers[i]) {
            hulk_trace_line("init %u 0x%08x", i, hulk_game_initializer_addrs[i]);
            hulk_game_initializers[i]();
        } else
            hulk_trace_line("skip %u 0x%08x (a library initializer, or no definition in the image)", i,
                            hulk_game_initializer_addrs[i]);
    }
    hulk_trace_line("initializers done");
    hulk_replay_startup();
    hulk_phase_ = "main";
    int r = hulk_game_main();
    hulk_phase_ = "exit";
    hulk_trace_line("main returned %d", r);
    hulk_crt_run_atexit();
    hulk_summary("returned", (hulk_u32)r);
    hulk_host_ExitProcess(0);
}

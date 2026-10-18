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
extern hulk_init_fn hulk_clang_xc_a[], hulk_clang_xc_z[];  // clang's own .CRT$XCU entries lie between
void HULK_CDECL hulk_crt_run_atexit(void);
}

static hulk_host_file* hulk_trace_;
static const char* hulk_phase_ = "start";
static hulk_u32 hulk_seq_;

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
    // the frame-pointer chain (the tree is compiled with frame pointers: -O0), within 1 MB of the first frame
    hulk_u32 first = ebp;
    for (int i = 0; i < 24 && ebp >= 0x10000 && (ebp & 3) == 0 && ebp - first < 0x100000; i++) {
        hulk_u32* f = (hulk_u32*)ebp;
        hulk_trace_line("frame %d ret=0x%08x", i, f[1]);
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
    hulk_summary("crash", ep->record->code);
    hulk_host_ExitProcess(4);
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

extern "C" void HULK_CDECL hulk_native_entry(void) {
    const char* path = hulk_host_getenv("HULK_TRACE_FILE");
    const char* child = hulk_host_getenv("HULK_NATIVE_CHILD");
    hulk_trace_ = hulk_host_fopen(path && *path ? path : "hulk-startup-trace.txt", child ? "a" : "w");
    if (!child && !hulk_host_getenv("HULK_NO_WINDOW"))
        hulk_run_child();  // (returns only if the child could not be started)
    hulk_xdk_first_call_sink = hulk_first_call;
    hulk_host_SetUnhandledExceptionFilter((void*)hulk_crash_filter);
    hulk_map_xbe_window();
    hulk_trace_line("start initializers=%u", hulk_game_initializer_count);
    char phase[32];
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
    hulk_phase_ = "main";
    int r = hulk_game_main();
    hulk_phase_ = "exit";
    hulk_trace_line("main returned %d", r);
    hulk_crt_run_atexit();
    hulk_summary("returned", (hulk_u32)r);
    hulk_host_ExitProcess(0);
}

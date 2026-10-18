// Stand-ins for the library code and data of library.h (xdk_shim.h counts and logs each call). Native builds only.
#include "library.h"
#include "../crt/host_crt.h"

extern "C" {

void hulk_native_missing(const char* name);

// Library data the game reads or writes by address: our own zeroed words. D3D's state block (D3D__RenderState,
// D3D__TextureState, D3D__DirtyFlags and their neighbours: the game's d3d8.h inlines write them directly), two
// DSOUND words, and XPP's device-type descriptors (the game passes their addresses to XGetDevices & co, which
// compare them by identity).
hulk_u32 hulk_lib_d3d_state[1136 / 4];
hulk_u32 hulk_lib_dsound_words[2];
hulk_u32 hulk_lib_xpp_gamepad_type[1] = {1};
hulk_u32 hulk_lib_xpp_mu_type[1] = {2};

#define HULK_LIB_STUB(name, args, body)                                \
    hulk_u32 HULK_STDCALL hulk_lib_##name args {                         \
        HULK_XDK_TRACE("lib:" #name);                                     \
        body;                                                             \
    }
HULK_LIB_STUB(XapiConvertTime, (hulk_u32 a, hulk_u32 out), (void)a; (void)out; return 0)
HULK_LIB_STUB(XapiCreatePath, (hulk_u32 path, hulk_u32 flag), (void)path; (void)flag; return 0)
HULK_LIB_STUB(XapiCheckPath, (hulk_u32 path), (void)path; return 0)
HULK_LIB_STUB(Bink_367610, (hulk_u32 a, hulk_u32 b, hulk_u32 c), (void)a; (void)b; (void)c; return 0)
HULK_LIB_STUB(Bink_367660, (hulk_u32 a, hulk_u32 b, hulk_u32 c, hulk_u32 d), (void)a; (void)b; (void)c; (void)d; return 0)
HULK_LIB_STUB(Direct3D_Object, (hulk_u32 a), (void)a; return 0)
HULK_LIB_STUB(D3DDevice_CreateIndexBuffer2, (hulk_u32 n), (void)n; return 0)
HULK_LIB_STUB(D3DDevice_SetRenderState_FogColor, (hulk_u32 v), (void)v; return 0)
HULK_LIB_STUB(D3DDevice_SetRenderState_StencilFail, (hulk_u32 v), (void)v; return 0)

// Kernel import slots: the game calls RtlInitialize/Enter/LeaveCriticalSection through the XBE's kernel thunk
// table (`call [slot]`, stdcall, one argument: the critical section, a 28-byte structure the game owns). Each game
// section gets a host CRITICAL_SECTION of its own in a table keyed by its address (the game's bytes are never used:
// their layout is the Xbox kernel's), created on first use, so a section entered before its initialization (or
// zero-initialized data the original relied on) still works. Windows / Wine host functions; an SDL3 backend
// replaces this with SDL_Mutex.
struct hulk_cs_slot {
    hulk_u32 key;
    hulk_u32 host[8];  // a host CRITICAL_SECTION (24 bytes on x86)
};
static hulk_cs_slot hulk_cs_table_[8192];
static hulk_u32 hulk_cs_lock_[8];
static int hulk_cs_ready_;

static void* hulk_cs_host(hulk_u32* cs) {
    if (!hulk_cs_ready_) {  // (the first call happens during the single-threaded start-up)
        hulk_host_InitializeCriticalSection(hulk_cs_lock_);
        hulk_cs_ready_ = 1;
    }
    hulk_u32 key = (hulk_u32)cs;
    hulk_u32 i = (key >> 2) * 2654435761u >> 19;  // 13 bits
    hulk_host_EnterCriticalSection(hulk_cs_lock_);
    for (hulk_u32 n = 0; n < 8192; n++, i = (i + 1) & 8191) {
        hulk_cs_slot* s = &hulk_cs_table_[i];
        if (s->key == key) {
            hulk_host_LeaveCriticalSection(hulk_cs_lock_);
            return s->host;
        }
        if (!s->key) {
            s->key = key;
            hulk_host_InitializeCriticalSection(s->host);
            hulk_host_LeaveCriticalSection(hulk_cs_lock_);
            return s->host;
        }
    }
    hulk_host_LeaveCriticalSection(hulk_cs_lock_);
    hulk_native_missing("kernel: more than 8192 critical sections");
    return 0;
}

static void HULK_STDCALL hulk_lib_RtlInitializeCriticalSection(hulk_u32* cs) {
    HULK_XDK_TRACE("kernel:RtlInitializeCriticalSection");
    if (cs)
        for (int i = 0; i < 7; i++)
            cs[i] = 0;
    hulk_cs_host(cs);
}
static void HULK_STDCALL hulk_lib_RtlEnterCriticalSection(hulk_u32* cs) {
    HULK_XDK_TRACE("kernel:RtlEnterCriticalSection");
    hulk_host_EnterCriticalSection(hulk_cs_host(cs));
}
static void HULK_STDCALL hulk_lib_RtlLeaveCriticalSection(hulk_u32* cs) {
    HULK_XDK_TRACE("kernel:RtlLeaveCriticalSection");
    hulk_host_LeaveCriticalSection(hulk_cs_host(cs));
}
void* hulk_lib_slot_RtlInitializeCriticalSection = (void*)hulk_lib_RtlInitializeCriticalSection;
void* hulk_lib_slot_RtlEnterCriticalSection = (void*)hulk_lib_RtlEnterCriticalSection;
void* hulk_lib_slot_RtlLeaveCriticalSection = (void*)hulk_lib_RtlLeaveCriticalSection;

}  // extern "C"

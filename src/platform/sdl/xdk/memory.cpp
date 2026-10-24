// Stand-ins for memory (xdk_shim.h counts and logs each call). The XAPI heaps become the host's C heap: a heap
// handle is a tag (never dereferenced by the game), each block is a host malloc block. Native builds only.
#include "imports.h"
#include "../crt/host_crt.h"

// MEMORYSTATUS (public Win32 layout): what the game reads is the physical memory; report the Xbox's 64 MB.
extern "C" hulk_u32 HULK_STDCALL hulk_xdk_GlobalMemoryStatus(hulk_uptr a0) {
    HULK_XDK_TRACE("GlobalMemoryStatus");
    hulk_u32* ms = (hulk_u32*)a0;
    if (ms) {
        ms[0] = 32;                  // dwLength
        ms[1] = 12;                  // dwMemoryLoad
        ms[2] = 64u << 20;           // dwTotalPhys
        ms[3] = 56u << 20;           // dwAvailPhys (a freshly booted title: ~8 MB in use)
        ms[4] = 64u << 20;           // dwTotalPageFile
        ms[5] = 32u << 20;           // dwAvailPageFile
        ms[6] = 0x7ff00000u;         // dwTotalVirtual
        ms[7] = 0x70000000u;         // dwAvailVirtual
    }
    return 0;
}

static hulk_u32 hulk_heaps_;

extern "C" hulk_uptr HULK_STDCALL hulk_xdk_HeapCreate(hulk_u32 a0, hulk_u32 a1, hulk_u32 a2) {
    (void)a0; (void)a1; (void)a2;
    HULK_XDK_TRACE("HeapCreate");
    return 0x48450000u + ++hulk_heaps_;  // a non-null tag
}

extern "C" hulk_uptr HULK_STDCALL hulk_xdk_HeapAlloc(hulk_uptr heap, hulk_u32 flags, hulk_u32 size) {
    (void)heap;
    HULK_XDK_TRACE("HeapAlloc");
    // zeroed whatever the flags (8 = HEAP_ZERO_MEMORY): the Xbox's heaps grow over fresh, zeroed pages, the host's
    // malloc recycles (crt_glue.cpp hulk_crt_malloc, docs/native-build.md native11)
    (void)flags;
    return (hulk_uptr)hulk_host_calloc(1, size ? size : 1);
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_HeapFree(hulk_uptr heap, hulk_u32 flags, hulk_uptr p) {
    (void)heap; (void)flags;
    HULK_XDK_TRACE("HeapFree");
    hulk_host_free((void*)p);
    return 1;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_HeapSize(hulk_uptr heap, hulk_u32 flags, hulk_uptr p) {
    (void)heap; (void)flags;
    HULK_XDK_TRACE("HeapSize");
    return p ? hulk_host__msize((void*)p) : 0xffffffffu;
}

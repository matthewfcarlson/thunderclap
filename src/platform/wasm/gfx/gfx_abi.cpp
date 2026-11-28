// The draw packets' layout as this module sees them (draw_sink.h on wasm32): the runner compares it with its
// wasm32 mirrors (src/platform/wasm/run/app/gfx_wire.h, GFX_ABI_TABLE) before the first sink call. The pointer-free
// structs must have one layout on both sides; the others differ only in their pointers' size.
#include <stddef.h>
#include <stdint.h>

#include "pddi/draw_sink.h"

using namespace hulk::pddi;

static_assert(offsetof(DrawPacket, instance) == 16 && offsetof(DrawPacket, vertexProgram) == 40,
              "gfx.c PKT_INSTANCE, PKT_VERTEX_PROGRAM (skins.c's tint tag)");

#define GFX_ABI_HOST 0
#include "../run/app/gfx_abi_table.h"

extern "C" uint32_t hulk_wasm_gfx_abi(uint32_t* table, uint32_t cap)
{
    const uint32_t t[] = {GFX_ABI_TABLE};
    uint32_t n = sizeof t / sizeof t[0];
    for (uint32_t i = 0; i < n && i < cap; i++)
        table[i] = t[i];
    return n;
}

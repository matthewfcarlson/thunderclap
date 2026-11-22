// The draw packets' layout check (src/platform/wasm/gfx/gfx_abi.cpp sends it, app.cpp compares): sizes of the
// pointer-free structs, and sizes and field offsets of the structs with pointers. GW(T) is draw_sink.h's T in the
// module and its wasm32 mirror (gfx_wire.h) in the runner.
#pragma once
#if GFX_ABI_HOST
#define GW(t) W##t
#else
#define GW(t) t
#endif
#define GFX_ABI_TABLE \
    sizeof(SinkVertex), sizeof(SinkCaps), sizeof(SinkTextureDesc), sizeof(SinkTarget), sizeof(SinkPass), \
    sizeof(SinkRenderState), sizeof(SinkStage), sizeof(SinkLight), sizeof(FxPacket), sizeof(SinkPresent), \
    sizeof(GW(SinkVertexData)), offsetof(GW(SinkVertexData), count), offsetof(GW(SinkVertexData), packed), \
    offsetof(GW(SinkVertexData), packedStride), offsetof(GW(SinkVertexData), primKind), \
    sizeof(GW(DrawPacket)), offsetof(GW(DrawPacket), instance), offsetof(GW(DrawPacket), programName), \
    offsetof(GW(DrawPacket), combinerKey), offsetof(GW(DrawPacket), combinerHash), \
    offsetof(GW(DrawPacket), vertexConstants), offsetof(GW(DrawPacket), vertexConstantCount), \
    offsetof(GW(DrawPacket), frag), offsetof(GW(DrawPacket), stage), offsetof(GW(DrawPacket), state), \
    offsetof(GW(DrawPacket), count), offsetof(GW(DrawPacket), pass), offsetof(GW(DrawPacket), modelview), \
    offsetof(GW(DrawPacket), lights), offsetof(GW(DrawPacket), material), offsetof(GW(DrawPacket), fog), \
    sizeof(GW(SinkInit)), offsetof(GW(SinkInit), width), offsetof(GW(SinkInit), renderer), \
    offsetof(GW(SinkInit), callback)

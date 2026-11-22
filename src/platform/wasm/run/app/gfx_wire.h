// draw_sink.h's structs with pointers as the module lays them out (wasm32: a pointer is a 32-bit offset into linear
// memory). Same fields in the same order, pointers as uint32_t; app.cpp converts them to the host's structs.
#pragma once
#include <stdint.h>

#include "pddi/draw_sink.h"

namespace hulk {
namespace pddi {

struct WSinkVertexData {
    uint32_t vertices;
    uint32_t count;
    uint32_t owner;
    uint32_t packed;
    uint32_t packedStride;
    uint32_t vertexFlags;
    uint32_t primKind;
};

struct WDrawPacket {
    uint32_t frame;
    uint32_t drawIndex;
    uint32_t phase;
    uint32_t pad0;
    uint64_t instance;
    uint32_t shaderKind;
    uint32_t shaderSerial;
    uint32_t bufferOwner;
    uint32_t viewMode;
    uint32_t vertexProgram;
    uint32_t programName;
    uint32_t combinerKey;
    uint32_t combinerHash;
    uint8_t forceGeneric;
    uint8_t generic;
    uint16_t pad1;
    uint32_t pipeline;
    uint32_t vertexConstants;
    uint32_t vertexConstantCount;
    float frag[16][4];
    SinkStage stage[4];
    SinkRenderState state;
    uint32_t count;
    uint32_t vertexCount;
    uint32_t transient;
    uint32_t vertexBuffer, indexBuffer;
    uint32_t query;
    uint16_t pass;
    uint16_t pad2;
    uint32_t modelview;
    uint32_t projection;
    uint32_t view;
    uint32_t lights;
    uint32_t material[4];
    float power;
    uint32_t ambient;
    uint32_t lighting;
    uint32_t fog;
};

struct WSinkInit {
    uint32_t nativeWindow;
    uint32_t nativeDisplay;
    uint32_t width, height;
    int32_t renderer;
    int32_t nativeType;
    uint32_t callback;
};

} // namespace pddi
} // namespace hulk

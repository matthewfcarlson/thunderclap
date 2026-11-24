// Helpers of the runner's full-screen passes (rm_post.h; wr3a, docs/hdr-shadows.md).
#include "rm_post.h"

#include <stdio.h>
#include <string.h>

#include <string>
#include <unordered_map>

#include <bgfx/bgfx.h>

#include "rm_pass.h"

namespace rm {

uint16_t program(const char* vs, const char* fs)
{
    static std::unordered_map<std::string, uint16_t> made;
    std::string key = std::string(vs) + "|" + fs;
    auto it = made.find(key);
    if (it != made.end())
        return it->second;
    uint16_t p = kNoHandle;
    uint16_t v = loadShader(vs), f = loadShader(fs);
    if (v != kNoHandle && f != kNoHandle) {
        bgfx::ProgramHandle h = bgfx::createProgram(bgfx::ShaderHandle{v}, bgfx::ShaderHandle{f}, false);
        if (bgfx::isValid(h))
            p = h.idx;
    }
    made[key] = p;
    return p;
}

bool Target::ensure(uint32_t nw, uint32_t nh, uint32_t nformat, bool blitDst, bool linear)
{
    nw = nw ? nw : 1, nh = nh ? nh : 1;
    if (tex != kNoHandle && w == nw && h == nh && format == nformat && blit == blitDst)
        return true;
    drop();
    uint64_t flags = BGFX_SAMPLER_U_CLAMP | BGFX_SAMPLER_V_CLAMP | (linear ? 0 : BGFX_SAMPLER_POINT) |
                     (blitDst ? BGFX_TEXTURE_BLIT_DST : BGFX_TEXTURE_RT);
    bgfx::TextureHandle t = bgfx::createTexture2D((uint16_t)nw, (uint16_t)nh, false, 1,
                                                  (bgfx::TextureFormat::Enum)nformat, flags);
    if (!bgfx::isValid(t))
        return false;
    tex = t.idx;
    if (!blitDst) {
        bgfx::FrameBufferHandle f = bgfx::createFrameBuffer(1, &t, true);
        if (!bgfx::isValid(f)) {
            bgfx::destroy(t);
            tex = kNoHandle;
            return false;
        }
        fb = f.idx;
    }
    w = nw, h = nh, format = nformat, blit = blitDst;
    return true;
}

void Target::drop()
{
    if (fb != kNoHandle)
        bgfx::destroy(bgfx::FrameBufferHandle{fb});         // (destroys its texture)
    else if (tex != kNoHandle)
        bgfx::destroy(bgfx::TextureHandle{tex});
    tex = fb = kNoHandle;
    w = h = 0;
}

void viewInto(uint16_t view, uint16_t fb, uint32_t w, uint32_t h, uint16_t clearFlags, uint32_t rgba, float depth)
{
    bgfx::setViewFrameBuffer(view, bgfx::FrameBufferHandle{fb});
    bgfx::setViewMode(view, bgfx::ViewMode::Sequential);
    bgfx::setViewRect(view, 0, 0, (uint16_t)w, (uint16_t)h);
    bgfx::setViewClear(view, clearFlags, rgba, depth, 0);
    bgfx::setViewTransform(view, nullptr, nullptr);
    bgfx::touch(view);
}

namespace {
uint16_t s_samplers[6] = {kNoHandle, kNoHandle, kNoHandle, kNoHandle, kNoHandle, kNoHandle};
std::unordered_map<std::string, uint16_t>& uniforms()
{
    static std::unordered_map<std::string, uint16_t> u;
    return u;
}
} // namespace

void texture(int stage, uint16_t tex, uint32_t flags)
{
    if (s_samplers[stage] == kNoHandle) {
        char name[16];
        snprintf(name, sizeof name, "s_rmTex%d", stage);
        s_samplers[stage] = bgfx::createUniform(name, bgfx::UniformType::Sampler).idx;
    }
    bgfx::setTexture((uint8_t)stage, bgfx::UniformHandle{s_samplers[stage]}, bgfx::TextureHandle{tex}, flags);
}

void uniform(const char* name, const float* v, uint16_t n)
{
    auto it = uniforms().find(name);
    uint16_t h;
    if (it == uniforms().end()) {
        h = bgfx::createUniform(name, bgfx::UniformType::Vec4, n).idx;
        uniforms()[name] = h;
    } else {
        h = it->second;
    }
    bgfx::setUniform(bgfx::UniformHandle{h}, v, n);
}

void quad(uint16_t view, uint16_t prog, uint64_t state)
{
    struct V { float x, y, z, u, v; };
    static bgfx::VertexLayout layout;
    static bool made;
    if (!made) {
        layout.begin()
            .add(bgfx::Attrib::Position, 3, bgfx::AttribType::Float)
            .add(bgfx::Attrib::TexCoord0, 2, bgfx::AttribType::Float)
            .end();
        made = true;
    }
    if (prog == kNoHandle || bgfx::getAvailTransientVertexBuffer(4, layout) < 4)
        return;
    bgfx::TransientVertexBuffer tvb;
    bgfx::allocTransientVertexBuffer(&tvb, 4, layout);
    const bgfx::Caps* caps = bgfx::getCaps();
    bool flip = caps && caps->originBottomLeft;
    float vt = flip ? 1.0f : 0.0f, vb = flip ? 0.0f : 1.0f;
    V q[4] = {{-1, 1, 0, 0, vt}, {1, 1, 0, 1, vt}, {-1, -1, 0, 0, vb}, {1, -1, 0, 1, vb}};
    memcpy(tvb.data, q, sizeof q);
    bgfx::setVertexBuffer(0, &tvb);
    bgfx::setState(state | BGFX_STATE_PT_TRISTRIP);
    bgfx::submit(view, bgfx::ProgramHandle{prog});
}

bool hdrSupported()
{
    const bgfx::Caps* caps = bgfx::getCaps();
    if (!caps)
        return false;
    const uint32_t need = BGFX_CAPS_FORMAT_TEXTURE_FRAMEBUFFER | BGFX_CAPS_FORMAT_TEXTURE_2D;
    return (caps->formats[bgfx::TextureFormat::RGBA16F] & need) == need;
}

} // namespace rm

// The runner's sampler bindings (rm_pass.h "wvk1"): every sampler a runner program declares is bound at each of its
// submits.
//
// bgfx drops every texture binding at each submit and each touch (a sink pass set, a split, a copy, an effect quad).
// A sampler a program declares that a submit leaves unbound reads zeros on Metal, but on Vulkan it is a descriptor
// never written: garbage, and on RADV a GPU page fault into VK_ERROR_DEVICE_LOST (wlinux2). The passes bind their own
// samplers in their draw hooks; when a later hook submits or touches before the draw reaches the sink, or a pass
// submits a copy of a draw without its bindings, a declared sampler goes unbound. So every runner binding, submit and
// sink draw comes through here (tests/test_rm_bind.py keeps run/app from calling bgfx or the sink around it):
//  - the stages bound since bgfx last dropped them are tracked;
//  - at a submit of a runner program (rm::program, the lighting pass's per-pixel programs: noteProgram), each declared
//    sampler left unbound is bound to a dummy (a 1x1 zero texture; the shadow pass's depth dummy for a compare sampler)
//    on every renderer but Metal (which reads zeros for it already: the macOS picture stays as it was);
//  - HULK_RM_BIND_CHECK=1 reports each (program, sampler, submit site) left unbound, on any renderer, with the pass
//    that bound it last and the call that dropped it: the check that runs on the Macs' Metal queue jobs.
#include "rm_pass.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <string>
#include <unordered_map>
#include <vector>

#include <bgfx/bgfx.h>

#include "pddi/bgfx_bridge.h"
#include "rm_post.h"
#include "shadows.h"

using namespace hulk::pddi;

namespace rm {

const char* g_hookPass = nullptr;   // (rm_pass.cpp RM_EACH: the pass whose hook is running)

namespace {

enum Kind : uint8_t { kColour, kCompare };
struct Decl {
    uint16_t uniform;
    uint8_t stage, kind;
    std::string name;
};
struct Prog {
    std::string name;
    std::vector<Decl> samplers;
};
std::unordered_map<uint16_t, Prog>& progs()
{
    static std::unordered_map<uint16_t, Prog> m;
    return m;
}

// the runner's samplers by name (run/app/shaders: SAMPLER2D(name, stage)); tests/test_rm_bind.py checks this table
// against the shaders, so a new sampler is added here with its stage
struct Known {
    const char* name;
    uint8_t stage, kind;
};
const Known kKnown[] = {
    {"s_rmShadow", 4, kCompare},  {"s_rmCity", 5, kColour},      {"s_rmSoftDepth", 6, kColour},
    {"s_rmDecalDepth", 6, kColour}, {"s_rmWaterScene", 4, kColour}, {"s_rmWaterDepth", 5, kColour},
};
// s_rmTexN / s_pddiTexN are at stage N; false: a sampler with no known stage
bool stageOf(const char* name, uint8_t* stage, uint8_t* kind)
{
    for (const Known& k : kKnown)
        if (!strcmp(k.name, name)) {
            *stage = k.stage, *kind = k.kind;
            return true;
        }
    for (const char* pre : {"s_rmTex", "s_pddiTex"}) {
        size_t n = strlen(pre);
        if (!strncmp(name, pre, n) && name[n] >= '0' && name[n] <= '9' && !name[n + 1]) {
            *stage = (uint8_t)(name[n] - '0'), *kind = kColour;
            return true;
        }
    }
    return false;
}

uint32_t s_bound;                   // stages bound since bgfx last dropped the bindings
const char* s_boundBy[16];          // (the check: the pass whose hook bound each stage last)
const char* s_dropped = "start";    // (the check: what dropped the bindings last)
const char* s_droppedBy = nullptr;
uint32_t s_frame;

int checkOn()
{
    static int on = -1;
    if (on < 0) {
        const char* e = getenv("HULK_RM_BIND_CHECK");
        on = e && *e && *e != '0' ? 1 : 0;
    }
    return on;
}
bool fillOn()
{
    static int on = -1;
    if (on < 0)
        on = bgfx::getRendererType() != bgfx::RendererType::Metal && bgfx::getRendererType() != bgfx::RendererType::Noop;
    return on != 0;
}

uint16_t s_zero = kNoHandle;
uint16_t zeroTexture()
{
    if (s_zero == kNoHandle) {
        static const uint32_t z = 0;
        bgfx::TextureHandle t = bgfx::createTexture2D(1, 1, false, 1, bgfx::TextureFormat::RGBA8,
                                                      BGFX_SAMPLER_POINT | BGFX_SAMPLER_UVW_CLAMP, bgfx::copy(&z, 4));
        s_zero = bgfx::isValid(t) ? t.idx : kNoHandle;
    }
    return s_zero;
}

// HULK_RM_BIND_CHECK: one line for each (site, program, sampler) the first time, then at 10, 100, 1000... and every
// 300 presented frames a summary of the frame's misses
struct Miss {
    unsigned count;
    uint32_t first;
};
std::unordered_map<std::string, Miss>& misses()
{
    static std::unordered_map<std::string, Miss> m;
    return m;
}
unsigned s_missTotal, s_draws;

void report(const char* who, const Prog& p, const Decl& d)
{
    char key[512];
    snprintf(key, sizeof key, "%s|%s|%s|%s|%s", who, p.name.c_str(), d.name.c_str(),
             s_boundBy[d.stage] ? s_boundBy[d.stage] : "-", s_droppedBy ? s_droppedBy : "-");
    Miss& m = misses()[key];
    if (!m.count)
        m.first = s_frame;
    m.count++;
    s_missTotal++;
    unsigned c = m.count;
    if (c == 1 || c == 10 || c == 100 || c == 1000 || c == 10000 || c == 100000)
        fprintf(stderr,
                "hulk-app: rm bind check: %s draw of %s left %s (stage %u) unbound (bound last by %s, dropped by %s "
                "in %s's hook); %u times since present %u\n",
                who, p.name.c_str(), d.name.c_str(), d.stage, s_boundBy[d.stage] ? s_boundBy[d.stage] : "nobody",
                s_dropped, s_droppedBy ? s_droppedBy : "no pass", c, m.first);
}

// every sampler `program` declares bound: the ones the caller left are reported (the check) and given dummies
void fill(uint16_t program, const char* who)
{
    auto it = progs().find(program);
    if (it == progs().end())
        return;
    s_draws++;
    const Prog& p = it->second;
    for (const Decl& d : p.samplers) {
        if (s_bound & (1u << d.stage))
            continue;
        if (checkOn())
            report(who, p, d);
        if (!fillOn())
            continue;
        uint16_t t = d.kind == kCompare ? rm::shadowDummy() : zeroTexture();
        if (t == kNoHandle)
            continue;
        uint32_t flags = d.kind == kCompare ? BGFX_SAMPLER_COMPARE_LEQUAL | BGFX_SAMPLER_U_CLAMP | BGFX_SAMPLER_V_CLAMP
                                            : BGFX_SAMPLER_POINT | BGFX_SAMPLER_UVW_CLAMP;
        bgfx::setTexture(d.stage, bgfx::UniformHandle{d.uniform}, bgfx::TextureHandle{t}, flags);
    }
}

bool s_inHooks, s_hookDrop;

void dropped(const char* why)
{
    if (s_inHooks)
        s_hookDrop = true;
    s_bound = 0;
    s_dropped = why;
    s_droppedBy = g_hookPass;
}

void addSamplers(Prog& p, uint16_t shader)
{
    if (shader == kNoHandle)
        return;
    bgfx::UniformHandle u[64];
    uint16_t n = bgfx::getShaderUniforms(bgfx::ShaderHandle{shader}, u, 64);
    for (uint16_t i = 0; i < n && i < 64; i++) {
        bgfx::UniformInfo info;
        bgfx::getUniformInfo(u[i], info);
        if (info.type != bgfx::UniformType::Sampler)
            continue;
        Decl d;
        d.uniform = u[i].idx;
        d.name = info.name;
        if (!stageOf(info.name, &d.stage, &d.kind)) {
            fprintf(stderr, "hulk-app: rm bind: %s declares %s, whose stage is unknown (rm_bind.cpp kKnown)\n",
                    p.name.c_str(), info.name);
            continue;
        }
        bool have = false;
        for (const Decl& e : p.samplers)
            have = have || e.stage == d.stage;
        if (!have)
            p.samplers.push_back(d);
    }
}

} // namespace

void noteProgram(uint16_t program, uint16_t vs, uint16_t fs, const char* name)
{
    if (program == kNoHandle)
        return;
    Prog p;
    p.name = name;
    addSamplers(p, vs);
    addSamplers(p, fs);
    progs()[program] = p;
}

void bindTexture(uint8_t stage, uint16_t sampler, uint16_t texture, uint32_t flags)
{
    if (texture == kNoHandle || sampler == kNoHandle)
        return;
    bgfx::setTexture(stage, bgfx::UniformHandle{sampler}, bgfx::TextureHandle{texture}, flags);
    if (stage < 16) {
        s_bound |= 1u << stage;
        s_boundBy[stage] = g_hookPass ? g_hookPass : "a submit site";
    }
}

void sinkDraw(const DrawPacket& q, const char* who)
{
    s_frame = q.frame;
    s_bound |= 0xf;                     // (the sink binds the game's stages 0..3 from the packet)
    fill((uint16_t)q.pipeline, who);
    hulk_gfx_sink_submit_draw(&q);
    dropped(who);
}

void submit(uint16_t view, uint16_t program, const char* who)
{
    fill(program, who);
    bgfx::submit(view, bgfx::ProgramHandle{program});
    dropped(who);
}

void touch(uint16_t view)
{
    bgfx::touch(view);
    dropped("a touch");
}

void bindingsDropped(const char* why) { dropped(why); }

void hooksBegin() { s_inHooks = true, s_hookDrop = false; }
bool hooksEnd()
{
    s_inHooks = false;
    return s_hookDrop;
}

void bindCheckFrame()
{
    static unsigned frames;
    if (!checkOn() || ++frames % 300)
        return;
    fprintf(stderr, "hulk-app: rm bind check: %u unbound samplers in %u runner draws over the last 300 presents\n",
            s_missTotal, s_draws);
    s_missTotal = s_draws = 0;
}

} // namespace rm

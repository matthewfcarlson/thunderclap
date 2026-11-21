// The semantic checkpoint probe (ckpt_probe.h; docs/checkpoints.md). Included, not compiled on its own: by
// hybrid/hooks.cpp (MSVC 7.1, the original's memory), src/platform/sdl/xdk/replay_hooks.cpp (the Wine build) and the
// native replay driver.
//
// Field access. A field the tree's gen headers spell is read through them when HULK_PROBE_GEN is defined (the Wine and
// native builds: offsetof follows the build's layout, and on a 32-bit build it is checked against the original's
// offset at compile time); the hook build reads the original's offsets directly. Fields gen does not spell yet, and
// pointer fields of objects gen only forward-declares, are read at their 32-bit offsets on 32-bit builds only: on a
// 64-bit build the tags that need them are reported unavailable (never hashed at a guessed offset). Each such read
// names the function that shows the offset.
#include "ckpt_probe.h"

#ifdef HULK_PROBE_GEN
#include <stddef.h>
#define HP_GEN_OFF(cls, field, off32) offsetof(::cls, field)
#define HP_CHECK(cls, field, off32) \
    typedef char hp_chk_##cls##_##field[(sizeof(void*) != 4 || offsetof(::cls, field) == (off32)) ? 1 : -1];
#else
#define HP_GEN_OFF(cls, field, off32) (off32)
#define HP_CHECK(cls, field, off32)
#endif

typedef unsigned int hp_u32;

// gen fields the probe reads (CCharacter: the actor's static ground point and health, 0x00026d50 / 0x000284c0;
// CScenarioManager: mission state 0x001cc620, checkpoint and clocks 0x001cc900 / 0x001cc860)
HP_CHECK(CCharacter, f_1a84, 0x1a84)
HP_CHECK(CCharacter, f_1b0c, 0x1b0c)
HP_CHECK(CScenarioManager, f_0c, 0x0c)
HP_CHECK(CScenarioManager, f_1194, 0x1194)
HP_CHECK(CScenarioManager, f_1198, 0x1198)
HP_CHECK(CScenarioManager, f_119c, 0x119c)
HP_CHECK(CCharacter, _pad_10, 0x10)

#define HP_RAW32_OK (sizeof(void*) == 4)

namespace {

struct HpHash {
    hp_u32 exact, quant;
    int tag;
    HulkProbeDump dump;
    void* ctx;
    unsigned index;
};

static hp_u32 hp_fnv(hp_u32 h, const void* p, unsigned n) {
    const unsigned char* b = (const unsigned char*)p;
    for (unsigned i = 0; i < n; i++)
        h = (h ^ b[i]) * 16777619u;
    return h;
}

static void hp_begin(HpHash* s, int tag, unsigned frame, HulkProbeDump dump, void* ctx) {
    unsigned char fb[8] = {(unsigned char)frame, (unsigned char)(frame >> 8), (unsigned char)(frame >> 16),
                           (unsigned char)(frame >> 24), (unsigned char)tag, 0, 0, HULK_PROBE_VERSION};
    s->exact = s->quant = hp_fnv(2166136261u, fb, 8);
    s->tag = tag;
    s->dump = dump;
    s->ctx = ctx;
    s->index = 0;
}

static void hp_u32v(HpHash* s, const char* name, hp_u32 v) {
    unsigned char b[4] = {(unsigned char)v, (unsigned char)(v >> 8), (unsigned char)(v >> 16), (unsigned char)(v >> 24)};
    s->exact = hp_fnv(s->exact, b, 4);
    s->quant = hp_fnv(s->quant, b, 4);
    if (s->dump)
        s->dump(s->ctx, s->tag, name, s->index, v, 0);
}

// A float's bits, exactly; in the quantised stream rounded to 10 fraction bits (NaN, infinities and zeros as they are)
static void hp_f32(HpHash* s, const char* name, hp_u32 bits) {
    unsigned char b[4] = {(unsigned char)bits, (unsigned char)(bits >> 8), (unsigned char)(bits >> 16),
                          (unsigned char)(bits >> 24)};
    s->exact = hp_fnv(s->exact, b, 4);
    hp_u32 q = bits;
    if ((bits & 0x7f800000u) != 0x7f800000u && (bits & 0x7fffffffu) != 0)
        q = (bits + (1u << 12)) & ~((1u << 13) - 1);
    unsigned char c[4] = {(unsigned char)q, (unsigned char)(q >> 8), (unsigned char)(q >> 16), (unsigned char)(q >> 24)};
    s->quant = hp_fnv(s->quant, c, 4);
    if (s->dump)
        s->dump(s->ctx, s->tag, name, s->index, bits, 1);
}

static hp_u32 hp_load32(const void* p) {
    const unsigned char* b = (const unsigned char*)p;
    return (hp_u32)b[0] | ((hp_u32)b[1] << 8) | ((hp_u32)b[2] << 16) | ((hp_u32)b[3] << 24);
}

// a pointer at a 32-bit offset (32-bit builds only)
static const char* hp_ptr32(const char* p, unsigned off) {
    if (!p)
        return 0;
    return *(const char* const*)(p + off);
}

static void hp_end(HpHash* s, HulkProbeRecord* out) {
    out->exact[s->tag] = s->exact;
    out->quant[s->tag] = s->quant;
    out->mask |= 1u << s->tag;
}

// One actor (CCharacter): life state (+0x20b0, 0x00028c60), controller slot (+0x20a8), health (gen f_1b0c), static
// ground point (gen f_1a84..), position (0x00059a50: the scene node +0x10, its drawable +0x18, translation +0x40; or
// the node's own +4). The 0x20a8 / 0x20b0 words and the node chain are 32-bit offsets (gen spells them as pads).
static void hp_actor(HpHash* s, const HulkProbeInputs* in, const char* actor) {
    hp_u32v(s, "present", actor ? 1 : 0);
    if (!actor)
        return;
    hp_u32v(s, "life_state", hp_load32(actor + 0x20b0));
    hp_u32v(s, "controller_slot", hp_load32(actor + 0x20a8));
    hp_f32(s, "health", hp_load32(actor + HP_GEN_OFF(CCharacter, f_1b0c, 0x1b0c)));
    const char* g = actor + HP_GEN_OFF(CCharacter, f_1a84, 0x1a84);
    hp_f32(s, "ground_x", hp_load32(g));
    hp_f32(s, "ground_y", hp_load32(g + 4));
    hp_f32(s, "ground_z", hp_load32(g + 8));
    // the scene node: CCharacter's first own word (gen's _pad_10, right after pure3d::Entity)
    const char* node = *(const char* const*)(actor + HP_GEN_OFF(CCharacter, _pad_10, 0x10));
    hp_u32 p[3] = {0, 0, 0};
    int have = 0;
    if (node && in->position_of) {
        have = in->position_of(node, p) ? 1 : 0;
    } else if (node) {
        const char* d = hp_ptr32(node, 0x18);
        const char* pos = d ? d + 0x40 : node + 4;
        p[0] = hp_load32(pos);
        p[1] = hp_load32(pos + 4);
        p[2] = hp_load32(pos + 8);
        have = 1;
    }
    hp_u32v(s, "has_position", have);
    if (have) {
        hp_f32(s, "pos_x", p[0]);
        hp_f32(s, "pos_y", p[1]);
        hp_f32(s, "pos_z", p[2]);
    }
}

}  // namespace

extern "C" void hulk_probe_frame(unsigned frame, const HulkProbeInputs* in, unsigned mask, HulkProbeRecord* out,
                                 HulkProbeDump dump, void* ctx) {
    HpHash s;
    out->frame = frame;
    out->mask = 0;
    out->unavailable = 0;
    for (int t = 0; t < HULK_PT_COUNT; t++)
        out->exact[t] = out->quant[t] = 0;
    // the world (0x4dd700) and its managers (Sim 0x00088670: +0x20 actor manager, +0x2c scenario manager)
    const char* world = in->world_ptr ? (const char*)*in->world_ptr : 0;
    const char* am = HP_RAW32_OK ? hp_ptr32(world, 0x20) : 0;
    const char* sm = HP_RAW32_OK ? hp_ptr32(world, 0x2c) : 0;
    if (mask & (1u << HULK_PT_FLOW)) {
        hp_begin(&s, HULK_PT_FLOW, frame, dump, ctx);
        hp_u32v(&s, "boot_step", in->boot_step ? hp_load32(in->boot_step) : 0xffffffffu);
        hp_u32v(&s, "world", world ? 1 : 0);
        hp_u32v(&s, "actor_manager", am ? 1 : 0);
        hp_u32v(&s, "mission_state", sm ? hp_load32(sm + HP_GEN_OFF(CScenarioManager, f_0c, 0x0c)) : 0xffffffffu);
        hp_end(&s, out);
        if (!HP_RAW32_OK)
            out->unavailable |= 1u << HULK_PT_FLOW;
    }
    if (mask & (1u << HULK_PT_CLOCK)) {
        hp_begin(&s, HULK_PT_CLOCK, frame, dump, ctx);
        hp_u32v(&s, "present", in->clock ? 1 : 0);
        if (in->clock) {
            // the GameClock block +0x10..+0x40 (six 64-bit fields; the same offsets natively: replay_native.cpp kLayout)
            const char* c = (const char*)in->clock + 0x10;
            for (unsigned i = 0; i < 12; i++) {
                s.index = i;
                int zero = in->clock_at_entry && i >= (0x28 - 0x10) / 4 && i < (0x38 - 0x10) / 4;
                hp_u32v(&s, "clock_word", zero ? 0 : hp_load32(c + i * 4));
            }
        }
        hp_end(&s, out);
    }
    if (mask & (1u << HULK_PT_RNG)) {
        hp_begin(&s, HULK_PT_RNG, frame, dump, ctx);
        for (unsigned i = 0; i < 2; i++) {
            s.index = i;
            hp_u32v(&s, "game_mwc", in->rng ? hp_load32((const char*)in->rng + i * 4) : 0);
        }
        hp_end(&s, out);
    }
    if (mask & (1u << HULK_PT_PARTICLE)) {
        hp_begin(&s, HULK_PT_PARTICLE, frame, dump, ctx);
        for (unsigned i = 0; i < 10; i++) {
            s.index = i;
            hp_u32v(&s, "particle", in->prng ? hp_load32(in->prng + i * 4) : 0);
        }
        hp_end(&s, out);
    }
    if (mask & (1u << HULK_PT_SOUND)) {
        // the sound code's own generators (sound-rng / seq-rng): which sounds get voices depends on the audio backend,
        // so this is an observable, compared apart from the game state
        hp_begin(&s, HULK_PT_SOUND, frame, dump, ctx);
        for (unsigned i = 0; i < 4; i++) {
            s.index = i;
            hp_u32v(&s, "sound_mwc", in->snd_rng ? hp_load32((const char*)in->snd_rng + i * 4) : 0);
        }
        s.index = 0;
        hp_u32v(&s, "sound_rand", in->snd_rand ? hp_load32(in->snd_rand) : 0);
        hp_end(&s, out);
    }
    if (mask & (1u << HULK_PT_HULK)) {
        // the main actor (CActorManager +0x124: am_GetMainCharacterName 0x000243d0)
        hp_begin(&s, HULK_PT_HULK, frame, dump, ctx);
        hp_actor(&s, in, HP_RAW32_OK ? hp_ptr32(am, 0x124) : 0);
        hp_end(&s, out);
        if (!HP_RAW32_OK)
            out->unavailable |= 1u << HULK_PT_HULK;
    }
    if (mask & (1u << HULK_PT_CAMERA)) {
        hp_begin(&s, HULK_PT_CAMERA, frame, dump, ctx);
        const char* v = in->view_ptr ? (const char*)*in->view_ptr : 0;
        hp_u32v(&s, "present", v ? 1 : 0);
        if (v) {   // (the logic view's position, rm_GetCameraPosition; +0x4c on both builds: replay_native.cpp kLayout)
            hp_f32(&s, "pos_x", hp_load32(v + 0x4c));
            hp_f32(&s, "pos_y", hp_load32(v + 0x50));
            hp_f32(&s, "pos_z", hp_load32(v + 0x54));
        }
        hp_end(&s, out);
    }
    if (mask & (1u << HULK_PT_ACTORS)) {
        // every actor of the actor manager: the inline handle list (+0xc count, +0x10 handles, 0x00024280) resolved
        // through the handle table (*(am) +0x44: 0x00059c10 / 0x00059ba0: +4 count, +8 items of 0x24 bytes (handle
        // at +0, actor at +0x10), +0xc in-use flags)
        hp_begin(&s, HULK_PT_ACTORS, frame, dump, ctx);
        hp_u32 n = am ? hp_load32(am + 0xc) : 0;
        hp_u32v(&s, "count", n);
        if (n > (0x124 - 0x10) / 4)
            n = 0;
        const char* table = hp_ptr32(hp_ptr32(am, 0), 0x44);
        hp_u32 tn = table ? hp_load32(table + 4) : 0;
        const char* items = hp_ptr32(table, 8);
        const char* flags = hp_ptr32(table, 0xc);
        for (hp_u32 i = 0; i < n; i++) {
            hp_u32 handle = hp_load32(am + 0x10 + i * 4);
            const char* actor = 0;
            if (in->actor_of) {
                actor = table ? (const char*)in->actor_of(table, handle) : 0;
            } else {
                for (hp_u32 k = 0; items && flags && k < tn; k++)
                    if (flags[k] && hp_load32(items + k * 0x24) == handle) {
                        actor = hp_ptr32(items + k * 0x24, 0x10);
                        break;
                    }
            }
            s.index = i;
            hp_actor(&s, in, actor);
        }
        hp_end(&s, out);
        if (!HP_RAW32_OK)
            out->unavailable |= 1u << HULK_PT_ACTORS;
    }
    if (mask & (1u << HULK_PT_MISSION)) {
        hp_begin(&s, HULK_PT_MISSION, frame, dump, ctx);
        hp_u32v(&s, "present", sm ? 1 : 0);
        if (sm) {
            hp_u32v(&s, "state", hp_load32(sm + HP_GEN_OFF(CScenarioManager, f_0c, 0x0c)));
            hp_u32v(&s, "checkpoint", hp_load32(sm + HP_GEN_OFF(CScenarioManager, f_1194, 0x1194)));
            hp_u32v(&s, "elapsed", hp_load32(sm + HP_GEN_OFF(CScenarioManager, f_1198, 0x1198)));
            hp_u32v(&s, "end_time", hp_load32(sm + HP_GEN_OFF(CScenarioManager, f_119c, 0x119c)));
        }
        hp_end(&s, out);
        if (!HP_RAW32_OK)
            out->unavailable |= 1u << HULK_PT_MISSION;
    }
}

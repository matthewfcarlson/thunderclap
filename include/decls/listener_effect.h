// (recs1, D144) audio::ListenerEffectXBox (vftable 0x004294a8; om entity type audio::ListenerEffectXBoxType, whose
// constructor 0x0024d7d0 gives instances 0x58 bytes, alignment 8): an om::Entity (records.h OmEntity), then the
// listener's twelve I3DL2 settings (`mHalListenerEffect`: vfunc_4 0x0024d640 hands them to 0x00241280, which copies
// the twelve words into the device's listener). 0x0024df00 builds the meta type's scalar attributes on these
// members: each attribute keeps the member's offset (OmMetaTypeAttribBase.offset), which is offsetof() on this record
// (natively the entity head is larger, so the members sit further in). Only the TUs that use it include this header
// (D74). Declare no namespaces here.
#ifndef HULK_DECLS_LISTENER_EFFECT_H
#define HULK_DECLS_LISTENER_EFFECT_H

#include "decls/data/records.h"

struct AudioHalListenerEffect {
    int room;                   // +0x00 (-10000 .. 0)
    int roomHF;                 // +0x04
    float roomRolloffFactor;    // +0x08
    float decayTime;            // +0x0c
    float decayHFRatio;         // +0x10
    int reflections;            // +0x14
    float reflectionsDelay;     // +0x18
    int reverb;                 // +0x1c
    float reverbDelay;          // +0x20
    float diffusion;            // +0x24
    float density;              // +0x28
    float hfReference;          // +0x2c
};

struct AudioListenerEffectXBox {
    OmEntity entity;                        // +0x00
    AudioHalListenerEffect hal;             // +0x28 mHalListenerEffect
};
HULK_SIZE32(AudioListenerEffectXBox, 0x58);

// HULK_LFX_AT(member): a member's offset in the record (an attribute's `offset`)
#if defined(__clang__)
#define HULK_LFX_AT(f) ((int)__builtin_offsetof(AudioListenerEffectXBox, f))
#else
#define HULK_LFX_AT(f) ((int)(hulk_uintptr) & (((AudioListenerEffectXBox*)0)->f))
#endif

#endif

// The sound resource manager (gfx7, C17): RTTI CSoundResourceManager (vftable 0x0042476c, a content::FileLoader),
// 0x524 bytes, allocated by 0x001f1270 and stored at DAT_004e3690 by 0x001ea8b0. Its words, from its users: the
// vftable and reference count; 100 sound sequences (0x001e97f0 adds, 0x001e8880 removes, 0x001e9860 / 0x001e98b0
// look up) and their count; 200 clip entries (0x001e8910 / 0x001ea190 add 0x14-byte entries, 0x001e9900 finds,
// 0x001e95c0 updates) and their count; 20 mixes (0x001e8960 adds, 0x001e9960 finds) and their count; the current mix
// (0x001e9b20); the clip inventory (0x001ea8b0 creates it; 0x001ea5a0 / 0x001ea700 look clips up in it); the
// parameter 0x001ea8b0 stores and a flag. Natively the pointer words widen: views size their pads by this record
// (HULK_SRM) and check their words' offsets (HULK_SRM_AT). Only the sound TUs include it (D74).
#ifndef HULK_DECLS_SOUND_RESOURCES_H
#define HULK_DECLS_SOUND_RESOURCES_H
#include "compat/ptr.h"

struct HulkSoundResources {
    void* vftable;
    int refs;
    void* sequences[100];
    int sequenceCount;
    void* clips[200];
    int clipCount;
    void* mixes[20];
    int mixCount;
    void* currentMix;
    void* inventory;
    int param;
    char flag;
    char pad521[3];
};

#if defined(__clang__)
#define HULK_SRM_OFF(T, f) __builtin_offsetof(T, f)
#else
#define HULK_SRM_OFF(T, f) ((unsigned int)(hulk_uintptr)&((T*)0)->f)
#endif
#define HULK_SRM(f) HULK_SRM_OFF(HulkSoundResources, f)
#define HULK_SRM_CAT2(a, b) a##b
#define HULK_SRM_CAT(a, b) HULK_SRM_CAT2(a, b)
#define HULK_SRM_CHECK(c) typedef char HULK_SRM_CAT(hulk_srm_at_, __LINE__)[(c) ? 1 : -1]
// HULK_SRM_AT(View, word, field): the view's word sits where the record's field does, on every build
#define HULK_SRM_AT(V, v, f) HULK_SRM_CHECK(HULK_SRM_OFF(V, v) == HULK_SRM(f))
// the XBE's size on the 32-bit builds
HULK_SRM_CHECK(sizeof(void*) != 4 || sizeof(HulkSoundResources) == 0x524);

#endif

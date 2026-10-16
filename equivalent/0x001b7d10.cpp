// STATUS: equivalent (tools/equiv.py level 3: 119 inputs, branch coverage 39/42, incomplete)
// FUN_001b7d10 @ 0x001b7d10
#include "decls/address.h"
class Source_1b7d10 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual int vf12();
    virtual void vf13();
    virtual float vf14();
    virtual unsigned int vf15();
};

class Mixer {
public:
    void FUN_001c05d0(float a, float b);
};

struct World {
    char pad0[0x50];
    Mixer *mixer;
};

class Pad_1b7d10 {
public:
    void FUN_000af0f0(unsigned int *out);
};

class PadManager {
public:
    Pad_1b7d10 *FUN_000af3a0(int index);
};

class Voices {
public:
    int pad0[4];
    int count;
    float FUN_000afe60();
    float FUN_000afe70();
    Voices *FUN_000afe40(int index);
    void FUN_000af530(int voice, int slot, float v);
    void FUN_000af650(int voice, int slot, int v);
};

struct Entry_1b7d10 {
    float time;
    float gain0;
    float gain1;
    int pan;
};

struct EntryList_1b7d10 {
    int count;
    Entry_1b7d10 entries[1];
};

struct Status_1b7d10 {
    int pad0;
    int state;
};


void FUN_00333ef0();
unsigned int FUN_00267f80();

class Player_1b7d10 {
public:
    void FUN_001b7d10(PadManager *pads, Voices *voices);
    void FUN_001b7970();

    char pad0[4];
    unsigned int deadline;
    char done;
    char restart;
    char pad1[2];
    Source_1b7d10 *source;
    char pad2[0x124 - 0x10];
    EntryList_1b7d10 *list;
    Status_1b7d10 *status;
};

void Player_1b7d10::FUN_001b7d10(PadManager *pads, Voices *voices)
{
    if (source == 0 || done)
        return;
    if (source->vf12() == 0) {
        FUN_00333ef0();
        FUN_001b7970();
        return;
    }
    if (status->state == -1) {
        FUN_001b7970();
        return;
    }
    float f = source->vf14();
    unsigned int n = source->vf15();
    DAT_004dd700->mixer->FUN_001c05d0((float)n, f);
    if (FUN_00267f80() >= deadline && status->state == -2 && pads != 0) {
        unsigned int pad[41];
        pads->FUN_000af3a0(0)->FUN_000af0f0(pad);
        if (pad[0] == 1 || pad[12] == 1 || pad[3] == 1 || pad[18] == 1) {
            status->state = 10;
            restart = 1;
        }
    }
    if (list == 0)
        return;
    if (voices == 0)
        return;
    for (int i = 0; i < list->count; i++) {
        Entry_1b7d10 *e = &list->entries[i];
        if (!(e->time > 0.0f))
            continue;
        int pos = source->vf15();
        if (pos < (int)(source->vf14() * e->time))
            continue;
        Voices *v = voices->FUN_000afe40(0);
        if (v == 0)
            continue;
        for (int s = 0; s < v->count; s++) {
            v->FUN_000af530(s, 0, voices->FUN_000afe60() * (e->gain0 * 0.01f));
            v->FUN_000af530(s, 1, voices->FUN_000afe70() * (e->gain1 * 0.01f));
            v->FUN_000af650(s, 0, e->pan);
            v->FUN_000af650(s, 1, e->pan);
        }
        e->time = -1.0f;
    }
}

// STATUS: equivalent (tools/equiv.py level 3: 91 inputs, branch coverage 53/58, incomplete)
// FUN_001bf9b0 @ 0x001bf9b0
#include "decls/data/game/global.h"

struct Owner_1bf9b0 {
    int FUN_000f7240(int a, int b);
    int FUN_000f7220(int index);
};

struct SubObj_1bf9b0 {
    char data[4];
};

struct Sink_1bf9b0 {
    char pad0[8];
    Owner_1bf9b0 *owner;
    bool flag;
    char padd[0x1c - 0xd];
    SubObj_1bf9b0 sub;
};

struct Key_1bf9b0 {
    float t;
    float dur;
    int a;
    int b;
};

void __cdecl FUN_000fb690(SubObj_1bf9b0 *sub, int value, int n);

class Track {
public:
    float time;
    int count;
    Key_1bf9b0 *keys;
    char pad0c;
    bool active;
    char pad0e[2];
    int keyA;
    int keyB;
    int subIndex;
    int subCount;
    int mode;
    char pad24;
    char pad25[3];
    int *handles;
    Sink_1bf9b0 *sink;
    char pad30[4];
    Owner_1bf9b0 *ownerA;
    Owner_1bf9b0 *ownerB;
    char pad3c[8];
    Owner_1bf9b0 *current;
    char pad48[8];
    int busy;
    char pad54;
    char flag55;

    int FUN_001bee10();
    void FUN_001bf9b0();
};

void Track::FUN_001bf9b0()
{
    int i = 0;
    float prevEnd = -1.0f;
    if (count <= 0)
        return;
    do {
        Key_1bf9b0 *k = &keys[i];
        float t0 = k->t;
        float t1 = DAT_004c4c10 + t0;
        if (k->dur > 0.0f) {
            t1 = t0 + k->dur;
        } else if (i >= count - 1) {
            t1 = DAT_004c4c14 + t0;
        } else {
            if (k[1].t > t1)
                t1 = k[1].t;
        }
        if (t0 > -1.0f) {
            if (!active) {
                if (time >= t0 && time > prevEnd) {
                    active = true;
                    keyA = k->a;
                    keyB = k->b;
                    int r = -1;
                    if (ownerA != 0) {
                        r = ownerA->FUN_000f7240(keyA, keyB);
                        if (r != -1) {
                            current = ownerA;
                            if (sink != 0)
                                sink->owner = ownerA;
                        }
                    }
                    if (r == -1) {
                        if (ownerB != 0) {
                            r = ownerB->FUN_000f7240(keyA, keyB);
                            if (r == -1) {
                                current = 0;
                                if (sink != 0)
                                    sink->owner = 0;
                                return;
                            }
                            current = ownerB;
                            if (sink != 0)
                                sink->owner = ownerB;
                        }
                    }
                    if (r == -1) {
                        current = 0;
                        if (sink != 0)
                            sink->owner = 0;
                        return;
                    }
                    subIndex = 0;
                    subCount = 1;
                    subCount = FUN_001bee10();
                }
            }
            if (active) {
                int c = subCount;
                if (c > 1) {
                    int step = subIndex + 1;
                    if (t0 + (t1 - t0) / c * step < time && subIndex < c - 1)
                        subIndex = step;
                }
            }
            if (time >= t1) {
                active = false;
                keys[i].t = -1.0f;
                if (i == count - 1 && busy == 0) {
                    count = 0;
                    time = -1.0f;
                    active = false;
                    pad24 = 0;
                    flag55 = 0;
                    if (mode == 2)
                        sink->flag = false;
                }
            }
            if (mode == 2) {
                sink->flag = active;
                if (active) {
                    if (subCount > 1) {
                        FUN_000fb690(&sink->sub, handles[subIndex], 0x80);
                    } else if (current != 0) {
                        int slot = current->FUN_000f7240(keyA, keyB);
                        FUN_000fb690(&sink->sub, current->FUN_000f7220(slot), 0x80);
                    }
                }
            }
        }
        prevEnd = t1;
        i++;
    } while (i < count);
}

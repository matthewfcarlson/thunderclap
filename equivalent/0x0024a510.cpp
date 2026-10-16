// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_0024a510 @ 0x0024a510
#include "decls/data/engine/audio.h"

struct ListLink {
    ListLink* next;
};

class Settings_24a510 {
public:
    char pad0[0x10];
    int owner;
    float scale0;
    float* pScaleA;
    float* pScaleB;
    float scale1;
    float scale2;
    float* pLimit;
    int zero2c;
    int* pMode;
    int* pCounter;
    float* pRate;
    int zero3c;
    int zero40;
    int zero44;
    int zero48;
    int zero4c;
    ListLink* link50;
    ListLink listA[3];  // 0x54: empty circular list (all links point at the head)
    int zero60;
    ListLink* link64;
    ListLink listB[3];  // 0x68: second empty circular list
    int zero74;
    Settings_24a510* FUN_0024a510(int ownerArg);
};

Settings_24a510* Settings_24a510::FUN_0024a510(int ownerArg) {
    owner = ownerArg;
    pScaleA = &DAT_004cc22c;
    pScaleB = &DAT_004cc228;
    pLimit = &DAT_004cc230;
    pMode = &DAT_004cc234;
    pCounter = ((int*)&DAT_004e5fa0);
    pRate = &DAT_004cc23c;
    zero2c = 0;
    zero3c = 0;
    zero40 = 0;
    zero44 = 0;
    scale0 = 1.0f;
    scale1 = 1.0f;
    scale2 = 1.0f;
    zero48 = 0;
    zero4c = 0;
    ListLink* a = &listA[0];
    listA[0].next = a;
    listA[1].next = a;
    listA[2].next = a;
    link50 = a;
    zero60 = 0;
    ListLink* b = &listB[0];
    listB[0].next = b;
    listB[1].next = b;
    listB[2].next = b;
    zero74 = 0;
    link64 = b;
    return this;
}

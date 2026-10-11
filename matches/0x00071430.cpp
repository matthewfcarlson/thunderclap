extern "C" char DAT_003fc624[];
extern "C" char DAT_003fc644[];
extern "C" char DAT_003fc664[];
extern "C" char DAT_004dcf68[];
extern "C" int gCount;
extern "C" void* __cdecl Alloc(unsigned int);
struct P {
    void InitFloat(const char*);
    void InitBool(const char*);
    void InitInt(const char*);
};
extern "C" void __cdecl Register(void**, void**, int);

void Target() {
    if (gCount == 0) {
        void* a[13];
        P* p;
#define M(i, n, f, v, d)                                                                                     \
    p = (P*)Alloc(24);                                                                                       \
    if (p) {                                                                                                 \
        p->f(n);                                                                                             \
        *(void**)p = (void*)v;                                                                               \
        *(void**)((char*)p + 16) = (void*)d;                                                                 \
        a[i] = p;                                                                                            \
    } else {                                                                                                 \
        a[i] = 0;                                                                                            \
    }
        M(0, "timeBegin", InitFloat, ((int)DAT_003fc624), 0x683b0)
        M(1, "timeEnd", InitFloat, ((int)DAT_003fc624), 0x683c0)
        M(2, "turningVelocity", InitFloat, ((int)DAT_003fc624), 0x69cf0)
        M(3, "arc", InitFloat, ((int)DAT_003fc624), 0x69d10)
        M(4, "distance", InitFloat, ((int)DAT_003fc624), 0x683d0)
        M(5, "checkDistance", InitBool, ((int)DAT_003fc644), 0x68410)
        M(6, "pickupPropTarget", InitBool, ((int)DAT_003fc644), 0x68440)
        M(7, "locator", InitBool, ((int)DAT_003fc644), 0x68470)
        M(8, "orientOffset", InitFloat, ((int)DAT_003fc624), 0x68480)
        M(9, "orientOffsetFromTarget", InitFloat, ((int)DAT_003fc624), 0x684a0)
        M(10, "priority", InitInt, ((int)DAT_003fc664), 0x684c0)
        M(11, "blendInTime", InitFloat, ((int)DAT_003fc624), 0x684d0)
        M(12, "blendOutTime", InitFloat, ((int)DAT_003fc624), 0x684e0)
        Register((void**)((int)DAT_004dcf68), a, 13);
    }
    ++gCount;
}

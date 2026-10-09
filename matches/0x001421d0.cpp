typedef unsigned int u32;
struct WallRunTrack {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual int vfunc_10(u32, u32, u32);
};
struct Helper {
    int run(WallRunTrack*, u32);
};
extern int __cdecl FUN_00344e74(u32, int, const void*, const void*, int);
extern void* __cdecl FUN_0008d690(unsigned int);
extern const char RTTI1[];
extern const char RTTI2[];
int WallRunTrack::vfunc_10(u32 a, u32 b, u32 c) {
    if (FUN_00344e74(c, 0, RTTI1, RTTI2, 0)) {
        void* p = FUN_0008d690(0x58);
        if (p)
            return ((Helper*)p)->run(this, c);
    }
    return 0;
}

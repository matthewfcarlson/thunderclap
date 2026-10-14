typedef unsigned int u32_1421d0;
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
    virtual int vfunc_10(u32_1421d0, u32_1421d0, u32_1421d0);
};
struct Helper_1421d0 {
    int run(WallRunTrack*, u32_1421d0);
};
extern int __cdecl FUN_00344e74(u32_1421d0, int, const void*, const void*, int);
extern void* __cdecl FUN_0008d690(unsigned int);
extern const char RTTI1_1421d0[];
extern const char RTTI2_1421d0[];
int WallRunTrack::vfunc_10(u32_1421d0 a, u32_1421d0 b, u32_1421d0 c) {
    if (FUN_00344e74(c, 0, RTTI1_1421d0, RTTI2_1421d0, 0)) {
        void* p = FUN_0008d690(0x58);
        if (p)
            return ((Helper_1421d0*)p)->run(this, c);
    }
    return 0;
}

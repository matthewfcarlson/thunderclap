// Same code shape as 0x001421d0 (propagated; names are from that function)
typedef unsigned int u32_17ba90;
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
    virtual int vfunc_10(u32_17ba90, u32_17ba90, u32_17ba90);
};
struct Helper_17ba90 {
    int run(WallRunTrack*, u32_17ba90);
};
extern int __cdecl FUN_00344e74(u32_17ba90, int, const void*, const void*, int);
extern void* __cdecl FUN_0008d690(unsigned int);
extern const char RTTI1_17ba90[];
extern const char RTTI2_17ba90[];
int WallRunTrack::vfunc_10(u32_17ba90 a, u32_17ba90 b, u32_17ba90 c) {
    if (FUN_00344e74(c, 0, RTTI1_17ba90, RTTI2_17ba90, 0)) {
        void* p = FUN_0008d690(0x58);
        if (p)
            return ((Helper_17ba90*)p)->run(this, c);
    }
    return 0;
}

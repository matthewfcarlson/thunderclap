// Same code shape as 0x001421d0 (propagated; names are from that function)
typedef unsigned int u32_156ff0;
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
    virtual int vfunc_10(u32_156ff0, u32_156ff0, u32_156ff0);
};
struct Helper_156ff0 {
    int run(WallRunTrack*, u32_156ff0);
};
extern int __cdecl FUN_00344e74(u32_156ff0, int, const void*, const void*, int);
extern void* __cdecl FUN_0008d690(unsigned int);
extern const char RTTI1_156ff0[];
extern const char RTTI2_156ff0[];
int WallRunTrack::vfunc_10(u32_156ff0 a, u32_156ff0 b, u32_156ff0 c) {
    if (FUN_00344e74(c, 0, RTTI1_156ff0, RTTI2_156ff0, 0)) {
        void* p = FUN_0008d690(0x58);
        if (p)
            return ((Helper_156ff0*)p)->run(this, c);
    }
    return 0;
}

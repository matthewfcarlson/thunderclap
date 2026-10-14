typedef unsigned int u32_17b1e0;
struct JointRelativeTrack {
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
    virtual int v10(u32_17b1e0 a, u32_17b1e0 b, u32_17b1e0 c);
};
struct Result_17b1e0 {
    int Init(JointRelativeTrack*, u32_17b1e0);
};
extern int __cdecl Check5(u32_17b1e0, int, void*, void*, int);
extern void* __cdecl Alloc(int);
extern char g_a_17b1e0;
extern char g_b_17b1e0;
int JointRelativeTrack::v10(u32_17b1e0 a, u32_17b1e0 b, u32_17b1e0 c) {
    if (Check5(c, 0, &g_b_17b1e0, &g_a_17b1e0, 0)) {
        Result_17b1e0* r = (Result_17b1e0*)Alloc(100);
        if (r)
            return r->Init(this, c);
    }
    return 0;
}

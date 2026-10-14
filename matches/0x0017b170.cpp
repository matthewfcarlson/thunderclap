typedef unsigned int u32_17b170;
extern int desc1_17b170;
extern int desc2_17b170;
int __cdecl check(void* obj, int z, void* d1, void* d2, int z2);
void* __cdecl alloc(int size);
struct Result_17b170 {
    int init(void* self, void* p);
};
struct Track {
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
    virtual int v10(u32_17b170, u32_17b170, void*);
};
struct JointPivotTrackerTrack : Track {
    int v10(u32_17b170 a, u32_17b170 b, void* c);
};
int JointPivotTrackerTrack::v10(u32_17b170 a, u32_17b170 b, void* c) {
    if (check(c, 0, &desc1_17b170, &desc2_17b170, 0)) {
        Result_17b170* p = (Result_17b170*)alloc(0x84);
        if (p)
            return p->init(this, c);
    }
    return 0;
}

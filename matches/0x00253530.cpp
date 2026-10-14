extern "C" void* __cdecl Alloc(void*);
extern int g_pool_253530;
extern int rand_vftable;
struct SeqEventVarPitchRand {
    int* vf;
    int pad;
    float a;
    float b;
    void init();
};
struct SeqEventVarPitchRandType {
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void* vfunc_3();
};
void* SeqEventVarPitchRandType::vfunc_3() {
    SeqEventVarPitchRand* p = (SeqEventVarPitchRand*)Alloc(&g_pool_253530);
    if (p) {
        p->init();
        p->vf = &rand_vftable;
        p->a = 0.8f;
        p->b = 1.2f;
        return p;
    }
    return 0;
}
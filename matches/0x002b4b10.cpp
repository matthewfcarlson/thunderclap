extern "C" char DAT_003f6098[];
extern "C" char DAT_0042e574[];
struct ShadowSkinTopology {
    void* vptr;
    int pad4;
    void* a;
    void* b;
    void* c;
    void Reset();
};
void ReleaseThing(void*);
void ShadowSkinTopology::Reset() {
    vptr = (void*)((int)DAT_0042e574);
    ReleaseThing(a);
    ReleaseThing(b);
    ReleaseThing(c);
    vptr = (void*)((int)DAT_003f6098);
}
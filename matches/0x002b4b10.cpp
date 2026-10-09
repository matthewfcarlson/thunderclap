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
    vptr = (void*)0x42e574;
    ReleaseThing(a);
    ReleaseThing(b);
    ReleaseThing(c);
    vptr = (void*)0x3f6098;
}
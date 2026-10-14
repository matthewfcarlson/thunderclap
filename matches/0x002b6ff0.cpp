extern void* shadowVftable;
extern void* refVftable;
struct Interface_2b6ff0 {
    virtual void a();
    virtual void b();
};
struct ShadowMeshBufferLoader {
    void* vptr;
    char pad[0x10];
    Interface_2b6ff0* member;
    ShadowMeshBufferLoader* f2(unsigned char);
};
extern void cleanup(ShadowMeshBufferLoader*);
ShadowMeshBufferLoader* ShadowMeshBufferLoader::f2(unsigned char flag) {
    vptr = &shadowVftable;
    member->b();
    vptr = &refVftable;
    if (flag & 1)
        cleanup(this);
    return this;
}
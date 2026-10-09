typedef unsigned char u8;
typedef unsigned int u32;
extern int shadow_vtable;
extern int ref_vtable;
void release(void*);
void release_self(void*);
class ShadowSkinTopology {
  public:
    virtual void v0();
    virtual void v1();
    virtual ShadowSkinTopology* vfunc_2(u8);
    u32 a;
    u32 b;
    u32 c;
    u32 d;
};
ShadowSkinTopology* ShadowSkinTopology::vfunc_2(u8 param) {
    *(int**)this = &shadow_vtable;
    release((void*)b);
    release((void*)c);
    release((void*)d);
    *(int**)this = &ref_vtable;
    if (param & 1)
        release_self((void*)this);
    return this;
}

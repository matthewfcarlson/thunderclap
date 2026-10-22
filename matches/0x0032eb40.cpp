struct Ref_32eb40 {
    virtual void f0();
    virtual void f1();
};
extern void* vtable_32eb40;
struct d3dLayeredLMapShader_32eb40 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual d3dLayeredLMapShader_32eb40* vfunc_3(unsigned int);
    char pad[0x98];
    Ref_32eb40* ref;
    void helper();
};
void thunk_FUN_00267090(d3dLayeredLMapShader_32eb40*);
d3dLayeredLMapShader_32eb40* d3dLayeredLMapShader_32eb40::vfunc_3(unsigned int flags) {
    *(void**)this = &vtable_32eb40;
    if (ref)
        ref->f1();
    helper();
    if (flags & 1)
        thunk_FUN_00267090(this);
    return this;
}
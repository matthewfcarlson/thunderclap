extern int vftable;
struct CSmartPropAttachTrack;
void FUN_00267090(CSmartPropAttachTrack*);
struct A {
    void f();
};
struct B {
    void f();
};
struct CSmartPropAttachTrack {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual CSmartPropAttachTrack* vfunc_5(unsigned char);
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    char pad[0x58 - 4];
};
CSmartPropAttachTrack* CSmartPropAttachTrack::vfunc_5(unsigned char p) {
    *(void**)this = &vftable;
    ((A*)((char*)this + 0x58))->f();
    ((A*)((char*)this + 0x20))->f();
    ((A*)((char*)this + 0x18))->f();
    ((B*)this)->f();
    if (p & 1)
        FUN_00267090(this);
    return this;
}
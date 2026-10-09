extern int grapple_vftable;
struct Sub { void f(); };
struct CGrappleSequenceTrack {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual CGrappleSequenceTrack* vfunc_5(unsigned char);
    virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10();
    char pad[0x28-4];
};
void thunk_FUN_00267090(CGrappleSequenceTrack*);
CGrappleSequenceTrack* CGrappleSequenceTrack::vfunc_5(unsigned char p) {
    *(int**)this = &grapple_vftable;
    ((Sub*)((char*)this + 0x1c))->f();
    ((Sub*)((char*)this + 0xc))->f();
    ((Sub*)this)->f();
    if (p & 1) thunk_FUN_00267090(this);
    return this;
}
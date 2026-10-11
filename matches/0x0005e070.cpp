extern "C" char DAT_003fa214[];
struct H1 {
    void f();
};
struct H2 {
    void f();
};
struct H3 {
    void f();
};
struct CCollisionTrack {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual CCollisionTrack* vfunc_5(int);
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    char pad[0x14];
};
void thunk_FUN_00267090(CCollisionTrack*);
CCollisionTrack* CCollisionTrack::vfunc_5(int flag) {
    *(unsigned long*)this = ((int)DAT_003fa214);
    ((H1*)((char*)this + 0x70))->f();
    ((H1*)((char*)this + 0x68))->f();
    ((H2*)((char*)this + 0x58))->f();
    ((H2*)((char*)this + 0x4c))->f();
    ((H1*)((char*)this + 0x18))->f();
    ((H3*)this)->f();
    if (flag & 1)
        thunk_FUN_00267090(this);
    return this;
}
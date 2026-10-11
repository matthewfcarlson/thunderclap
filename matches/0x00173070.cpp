extern "C" char DAT_00417b38[];
class Sub {
  public:
    void Init();
};
class PushOutTrack {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual PushOutTrack* vfunc_5(int);
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    char pad[0x14];
    void Middle();
};
extern void __cdecl thunk_FUN_00267090(PushOutTrack*);
PushOutTrack* PushOutTrack::vfunc_5(int flag) {
    *(int*)this = ((int)DAT_00417b38);
    Sub* p = (Sub*)((char*)this + 0x18);
    p->Init();
    Middle();
    if (flag & 1)
        thunk_FUN_00267090(this);
    return this;
}
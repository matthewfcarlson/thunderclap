class Sub {
  public:
    Sub();
};
class HitReactionTrack {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    char pad[0x14];
    Sub sub;
    void BaseCall();
    HitReactionTrack(int);
};
extern void __cdecl thunk_FUN_00267090(HitReactionTrack*);
HitReactionTrack::HitReactionTrack(int flag) {
    BaseCall();
    if (flag & 1)
        thunk_FUN_00267090(this);
}
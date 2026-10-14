extern char SequenceTrack_vftable[];
class SubA_237c50 {
  public:
    void Init();
};
class SubB_237c50 {
  public:
    void Init();
};
class SequenceTrack {
  public:
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual SequenceTrack* V5(int);
    virtual void V6();
    virtual void V7();
    virtual void V8();
    virtual void V9();
    virtual void V10();
    char p[8];
    SubB_237c50 b;
    char q[0xf];
    SubA_237c50 a1;
    char r[8];
    void Finish();
};
void __cdecl thunk_FUN_00267090(SequenceTrack*);
SequenceTrack* SequenceTrack::V5(int x) {
    *(char**)this = SequenceTrack_vftable;
    a1.Init();
    b.Init();
    Finish();
    if (x & 1)
        thunk_FUN_00267090(this);
    return this;
}
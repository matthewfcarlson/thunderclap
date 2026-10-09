class ExecuteTrack {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual ExecuteTrack* vfunc_5(int);
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    char pad[0x2c];
};
class A {
  public:
    void First();
};
class B {
  public:
    void Second();
};
class C {
  public:
    void Third();
};
extern void __cdecl thunk_FUN_00267090(ExecuteTrack*);
ExecuteTrack* ExecuteTrack::vfunc_5(int flags) {
    ExecuteTrack* p = this;
    *(unsigned long*)p = 0x428418;
    ((A*)((char*)p + 0x24))->First();
    ((B*)((char*)p + 0x14))->Second();
    ((C*)p)->Third();
    if (flags & 1)
        thunk_FUN_00267090(p);
    return p;
}
class Ref {
  public:
    virtual void f0();
    virtual void Release();
};
class Target {
  public:
    char pad[8];
    Ref* mRef;
    int Destroy(int flags);
};
extern void __cdecl thunk_FUN_00267090(Target*);
int Target::Destroy(int flags) {
    if (mRef) {
        mRef->Release();
        mRef = 0;
    }
    if (flags & 1)
        thunk_FUN_00267090(this);
    return (int)this;
}
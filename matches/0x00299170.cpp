class Ref_299170 {
  public:
    virtual void f0();
    virtual void Release();
};
class Target_299170 {
  public:
    char pad[8];
    Ref_299170* mRef;
    int Destroy(int flags);
};
extern void __cdecl thunk_FUN_00267090(Target_299170*);
int Target_299170::Destroy(int flags) {
    if (mRef) {
        mRef->Release();
        mRef = 0;
    }
    if (flags & 1)
        thunk_FUN_00267090(this);
    return (int)this;
}
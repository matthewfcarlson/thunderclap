extern "C" char DAT_004279fc[];
class Inner {
  public:
    void Init();
};
extern void __cdecl thunk_FUN_00267090(void*);
class ParamValue {
  public:
    virtual void* v0(unsigned int);
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
};
class ParamValueBranch : public ParamValue {
  public:
    virtual void* v0(unsigned int);
};
void* ParamValueBranch::v0(unsigned int flags) {
    *(int*)this = ((int)DAT_004279fc);
    ((Inner*)((char*)this + 8))->Init();
    if (flags & 1)
        thunk_FUN_00267090(this);
    return this;
}
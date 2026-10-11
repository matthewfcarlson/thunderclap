extern "C" char DAT_004279fc[];
class Sub {
  public:
    void init();
};
class ParamValueNameList {
  public:
    virtual ParamValueNameList* f0(int);
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    int pad;
    Sub sub;
};
extern void __cdecl thunk_FUN_00267090(ParamValueNameList*);
ParamValueNameList* ParamValueNameList::f0(int flag) {
    ParamValueNameList* p = this;
    *(void**)p = (void*)((int)DAT_004279fc);
    p->sub.init();
    if (flag & 1)
        thunk_FUN_00267090(p);
    return p;
}

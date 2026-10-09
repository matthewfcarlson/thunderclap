class StateProp {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual int vfunc_4();
};
class Obj {
  public:
    int call(StateProp*);
};
extern void* __cdecl thunk_FUN_0008d690(int);
int StateProp::vfunc_4() {
    void* p = thunk_FUN_0008d690(0xe8);
    if (p)
        return ((Obj*)p)->call(this);
    return 0;
}
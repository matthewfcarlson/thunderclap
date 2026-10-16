// Same code shape as 0x00234ac0 (propagated; names are from that function)
class ParamValueString {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void* get(void*);
};
namespace fight { class ParamValueNameList : public ParamValueString {
  public:
    bool vfunc_6(void*, void*);
}; }
class Receiver_234bd0 {
  public:
    void run(void*);
};
bool fight::ParamValueNameList::vfunc_6(void* a, void* b) {
    void* x = get(a);
    if (!x)
        return false;
    ((Receiver_234bd0*)x)->run(b);
    return true;
}
class Helper_49d40 {
  public:
    void* First();
    void* Second();
};
class CIsGrappledCondition {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual bool vfunc_7(Helper_49d40*);
};
bool CIsGrappledCondition::vfunc_7(Helper_49d40* p) {
    void* a = p->First();
    void* b = ((Helper_49d40*)a)->Second();
    return *(int*)((char*)b + 0x338) != 0;
}
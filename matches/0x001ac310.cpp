class ConditionFactoryCasterTemplate_1ac310 {
  public:
    virtual void cast();
};
class Obj {
  public:
    void apply(void*);
};
extern "C" void* __cdecl find(void*, ConditionFactoryCasterTemplate_1ac310*);
void func(Obj* obj, void* arg) {
    ConditionFactoryCasterTemplate_1ac310 c;
    obj->apply(find(arg, &c));
}
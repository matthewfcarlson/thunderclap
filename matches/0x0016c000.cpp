class ConditionFactoryCasterTemplate_16c000 {
  public:
    virtual void f();
};
extern "C" void __cdecl FUN_002343e0(void*, ConditionFactoryCasterTemplate_16c000*);
void __cdecl target(void* p) {
    ConditionFactoryCasterTemplate_16c000 c;
    FUN_002343e0(p, &c);
}
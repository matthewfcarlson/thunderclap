class ConditionFactoryCasterTemplate_16c000 {
  public:
    virtual void f();
};
void __cdecl use(void*, ConditionFactoryCasterTemplate_16c000*);
void __cdecl target(void* p) {
    ConditionFactoryCasterTemplate_16c000 c;
    use(p, &c);
}
class CCollisionHitLocationCondition {};
class ConditionFactoryCasterTemplate_54c30 {
  public:
    virtual void cast();
    ConditionFactoryCasterTemplate_54c30() {}
};
void __cdecl findCondition(void*, ConditionFactoryCasterTemplate_54c30*);
void __cdecl FUN_00054c30(void* p) {
    ConditionFactoryCasterTemplate_54c30 c;
    findCondition(p, &c);
}

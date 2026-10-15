// Same code shape as 0x00048300 (propagated; names are from that function)
extern int* gTable_49250;
class CCondition {
  public:
    virtual int vfunc_0(int);
};
class CSmartPropWeaponizableTypeCondition : public CCondition {
  public:
    int vfunc_0(int);
};
int CSmartPropWeaponizableTypeCondition::vfunc_0(int index) {
    int* p = gTable_49250;
    return p[index];
}

// Same code shape as 0x00048300 (propagated; names are from that function)
extern int* gTable_48d50;
class CCondition {
  public:
    virtual int vfunc_0(int);
};
class CNameFlagConditionBase : public CCondition {
  public:
    int vfunc_0(int);
};
int CNameFlagConditionBase::vfunc_0(int index) {
    int* p = gTable_48d50;
    return p[index];
}

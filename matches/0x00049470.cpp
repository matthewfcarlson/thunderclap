// Same code shape as 0x00048300 (propagated; names are from that function)
extern int* gTable_49470;
class CCondition {
  public:
    virtual int vfunc_0(int);
};
class CSmartPropTypeCondition : public CCondition {
  public:
    int vfunc_0(int);
};
int CSmartPropTypeCondition::vfunc_0(int index) {
    int* p = gTable_49470;
    return p[index];
}

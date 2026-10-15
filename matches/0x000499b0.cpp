// Same code shape as 0x00048300 (propagated; names are from that function)
extern int* gTable_499b0;
class CCondition {
  public:
    virtual int vfunc_0(int);
};
class CSmartPropCSMableCondition : public CCondition {
  public:
    int vfunc_0(int);
};
int CSmartPropCSMableCondition::vfunc_0(int index) {
    int* p = gTable_499b0;
    return p[index];
}

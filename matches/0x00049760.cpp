// Same code shape as 0x00048300 (propagated; names are from that function)
extern int* gTable_49760;
class CCondition {
  public:
    virtual int vfunc_0(int);
};
class CSmartPropAngleCondition : public CCondition {
  public:
    int vfunc_0(int);
};
int CSmartPropAngleCondition::vfunc_0(int index) {
    int* p = gTable_49760;
    return p[index];
}

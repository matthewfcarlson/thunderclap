// Same code shape as 0x00048300 (propagated; names are from that function)
extern int* gTable_49a10;
class CCondition {
  public:
    virtual int vfunc_0(int);
};
class CSmartPropStateCondition : public CCondition {
  public:
    int vfunc_0(int);
};
int CSmartPropStateCondition::vfunc_0(int index) {
    int* p = gTable_49a10;
    return p[index];
}

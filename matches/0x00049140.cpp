// Same code shape as 0x00048300 (propagated; names are from that function)
extern int* gTable_49140;
class CCondition {
  public:
    virtual int vfunc_0(int);
};
class CSmartPropAttachedCondition : public CCondition {
  public:
    int vfunc_0(int);
};
int CSmartPropAttachedCondition::vfunc_0(int index) {
    int* p = gTable_49140;
    return p[index];
}

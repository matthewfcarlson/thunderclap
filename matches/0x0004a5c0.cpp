// Same code shape as 0x00048300 (propagated; names are from that function)
extern int* gTable_4a5c0;
class CCondition {
  public:
    virtual int vfunc_0(int);
};
class CRageModeCondition : public CCondition {
  public:
    int vfunc_0(int);
};
int CRageModeCondition::vfunc_0(int index) {
    int* p = gTable_4a5c0;
    return p[index];
}

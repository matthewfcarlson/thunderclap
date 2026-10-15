// Same code shape as 0x00048300 (propagated; names are from that function)
extern int* gTable_48780;
class CCondition {
  public:
    virtual int vfunc_0(int);
};
class CAxisValueCondition : public CCondition {
  public:
    int vfunc_0(int);
};
int CAxisValueCondition::vfunc_0(int index) {
    int* p = gTable_48780;
    return p[index];
}

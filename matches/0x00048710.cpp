// Same code shape as 0x00048300 (propagated; names are from that function)
extern int* gTable_48710;
class CCondition {
  public:
    virtual int vfunc_0(int);
};
class CAxisSpeedCondition : public CCondition {
  public:
    int vfunc_0(int);
};
int CAxisSpeedCondition::vfunc_0(int index) {
    int* p = gTable_48710;
    return p[index];
}

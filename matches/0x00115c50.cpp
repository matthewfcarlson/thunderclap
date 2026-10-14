// Same code shape as 0x00048300 (propagated; names are from that function)
extern int* gTable_115c50;
class CCondition {
  public:
    virtual int vfunc_0(int);
};
class CStageCondition : public CCondition {
  public:
    int vfunc_0(int);
};
int CStageCondition::vfunc_0(int index) {
    int* p = gTable_115c50;
    return p[index];
}

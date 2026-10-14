// Same code shape as 0x00048300 (propagated; names are from that function)
extern int* gTable_181410;
class CCondition {
  public:
    virtual int vfunc_0(int);
};
class CStageCondition : public CCondition {
  public:
    int vfunc_0(int);
};
int CStageCondition::vfunc_0(int index) {
    int* p = gTable_181410;
    return p[index];
}

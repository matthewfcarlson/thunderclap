// Same code shape as 0x00048300 (propagated; names are from that function)
extern int* gTable_4ade0;
class CCondition {
  public:
    virtual int vfunc_0(int);
};
class CMotionClimbAngleCondition : public CCondition {
  public:
    int vfunc_0(int);
};
int CMotionClimbAngleCondition::vfunc_0(int index) {
    int* p = gTable_4ade0;
    return p[index];
}

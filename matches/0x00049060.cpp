// Same code shape as 0x00048300 (propagated; names are from that function)
extern int* gTable_49060;
class CCondition {
  public:
    virtual int vfunc_0(int);
};
class CCollisionPushbackYAngleCondition : public CCondition {
  public:
    int vfunc_0(int);
};
int CCollisionPushbackYAngleCondition::vfunc_0(int index) {
    int* p = gTable_49060;
    return p[index];
}

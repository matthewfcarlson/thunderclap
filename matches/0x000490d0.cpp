// Same code shape as 0x00048300 (propagated; names are from that function)
extern int* gTable_490d0;
class CCondition {
  public:
    virtual int vfunc_0(int);
};
class CCollisionStunTimeCondition : public CCondition {
  public:
    int vfunc_0(int);
};
int CCollisionStunTimeCondition::vfunc_0(int index) {
    int* p = gTable_490d0;
    return p[index];
}

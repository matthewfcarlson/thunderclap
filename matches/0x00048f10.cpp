// Same code shape as 0x00048300 (propagated; names are from that function)
extern int* gTable_48f10;
class CCondition {
  public:
    virtual int vfunc_0(int);
};
class CCollisionHeightCondition : public CCondition {
  public:
    int vfunc_0(int);
};
int CCollisionHeightCondition::vfunc_0(int index) {
    int* p = gTable_48f10;
    return p[index];
}

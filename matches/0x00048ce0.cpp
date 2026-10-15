// Same code shape as 0x00048300 (propagated; names are from that function)
extern int* gTable_48ce0;
class CCondition {
  public:
    virtual int vfunc_0(int);
};
class CCollisionPushbackDirectionCondition : public CCondition {
  public:
    int vfunc_0(int);
};
int CCollisionPushbackDirectionCondition::vfunc_0(int index) {
    int* p = gTable_48ce0;
    return p[index];
}

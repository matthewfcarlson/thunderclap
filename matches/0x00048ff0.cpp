// Same code shape as 0x00048300 (propagated; names are from that function)
extern int* gTable_48ff0;
class CCondition {
  public:
    virtual int vfunc_0(int);
};
class CCollisionPushbackYCondition : public CCondition {
  public:
    int vfunc_0(int);
};
int CCollisionPushbackYCondition::vfunc_0(int index) {
    int* p = gTable_48ff0;
    return p[index];
}

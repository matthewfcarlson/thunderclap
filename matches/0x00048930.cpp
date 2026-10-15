// Same code shape as 0x00048300 (propagated; names are from that function)
extern int* gTable_48930;
class CCondition {
  public:
    virtual int vfunc_0(int);
};
class CAxisDoubleTapCondition : public CCondition {
  public:
    int vfunc_0(int);
};
int CAxisDoubleTapCondition::vfunc_0(int index) {
    int* p = gTable_48930;
    return p[index];
}

// Same code shape as 0x00048300 (propagated; names are from that function)
extern int* gTable_48510;
class CCondition {
  public:
    virtual int vfunc_0(int);
};
class CButtonValueCondition : public CCondition {
  public:
    int vfunc_0(int);
};
int CButtonValueCondition::vfunc_0(int index) {
    int* p = gTable_48510;
    return p[index];
}

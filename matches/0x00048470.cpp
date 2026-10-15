// Same code shape as 0x00048300 (propagated; names are from that function)
extern int* gTable_48470;
class CCondition {
  public:
    virtual int vfunc_0(int);
};
class CButtonCondition : public CCondition {
  public:
    int vfunc_0(int);
};
int CButtonCondition::vfunc_0(int index) {
    int* p = gTable_48470;
    return p[index];
}

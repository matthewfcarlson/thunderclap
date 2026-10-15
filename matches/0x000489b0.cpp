// Same code shape as 0x00048300 (propagated; names are from that function)
extern int* gTable_489b0;
class CCondition {
  public:
    virtual int vfunc_0(int);
};
class CAxisDirectionCondition : public CCondition {
  public:
    int vfunc_0(int);
};
int CAxisDirectionCondition::vfunc_0(int index) {
    int* p = gTable_489b0;
    return p[index];
}

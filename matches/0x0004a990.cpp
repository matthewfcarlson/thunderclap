// Same code shape as 0x00048300 (propagated; names are from that function)
extern int* gTable_4a990;
class CCondition {
  public:
    virtual int vfunc_0(int);
};
class CClimbEdgeCondition : public CCondition {
  public:
    int vfunc_0(int);
};
int CClimbEdgeCondition::vfunc_0(int index) {
    int* p = gTable_4a990;
    return p[index];
}

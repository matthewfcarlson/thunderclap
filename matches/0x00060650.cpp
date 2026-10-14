// Same code shape as 0x00048300 (propagated; names are from that function)
extern int* gTable_60650;
class CCondition {
  public:
    virtual int vfunc_0(int);
};
class CStageCondition : public CCondition {
  public:
    int vfunc_0(int);
};
int CStageCondition::vfunc_0(int index) {
    int* p = gTable_60650;
    return p[index];
}

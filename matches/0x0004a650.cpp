// Same code shape as 0x00048300 (propagated; names are from that function)
extern int* gTable_4a650;
class CCondition {
  public:
    virtual int vfunc_0(int);
};
class CGrappleTimerCondition : public CCondition {
  public:
    int vfunc_0(int);
};
int CGrappleTimerCondition::vfunc_0(int index) {
    int* p = gTable_4a650;
    return p[index];
}

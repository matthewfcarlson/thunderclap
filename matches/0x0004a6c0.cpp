// Same code shape as 0x00048300 (propagated; names are from that function)
extern int* gTable_4a6c0;
class CCondition {
  public:
    virtual int vfunc_0(int);
};
class CInactivityTimerCondition : public CCondition {
  public:
    int vfunc_0(int);
};
int CInactivityTimerCondition::vfunc_0(int index) {
    int* p = gTable_4a6c0;
    return p[index];
}

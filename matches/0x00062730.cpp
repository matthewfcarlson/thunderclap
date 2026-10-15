// Same code shape as 0x00048300 (propagated; names are from that function)
extern int* gTable_62730;
class CCondition {
  public:
    virtual int vfunc_0(int);
};
class CSmartPropSetStateTrack : public CCondition {
  public:
    int vfunc_0(int);
};
int CSmartPropSetStateTrack::vfunc_0(int index) {
    int* p = gTable_62730;
    return p[index];
}

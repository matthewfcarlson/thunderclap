// Same code shape as 0x00048300 (propagated; names are from that function)
extern int* gTable_62c00;
class CCondition {
  public:
    virtual int vfunc_0(int);
};
class CSmartPropRemoveInstanceTrack : public CCondition {
  public:
    int vfunc_0(int);
};
int CSmartPropRemoveInstanceTrack::vfunc_0(int index) {
    int* p = gTable_62c00;
    return p[index];
}

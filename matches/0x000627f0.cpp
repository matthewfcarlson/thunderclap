// Same code shape as 0x00048300 (propagated; names are from that function)
extern int* gTable_627f0;
class CCondition {
  public:
    virtual int vfunc_0(int);
};
class CSmartPropDetachTrack : public CCondition {
  public:
    int vfunc_0(int);
};
int CSmartPropDetachTrack::vfunc_0(int index) {
    int* p = gTable_627f0;
    return p[index];
}

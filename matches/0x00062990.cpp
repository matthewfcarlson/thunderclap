// Same code shape as 0x00048300 (propagated; names are from that function)
extern int* gTable_62990;
class CCondition {
  public:
    virtual int vfunc_0(int);
};
class CSmartPropThrowingTrack : public CCondition {
  public:
    int vfunc_0(int);
};
int CSmartPropThrowingTrack::vfunc_0(int index) {
    int* p = gTable_62990;
    return p[index];
}

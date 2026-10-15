// Same code shape as 0x00048300 (propagated; names are from that function)
extern int* gTable_62500;
class CCondition {
  public:
    virtual int vfunc_0(int);
};
class CSmartPropSpawnTrack : public CCondition {
  public:
    int vfunc_0(int);
};
int CSmartPropSpawnTrack::vfunc_0(int index) {
    int* p = gTable_62500;
    return p[index];
}

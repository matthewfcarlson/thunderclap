// Same code shape as 0x00048300 (propagated; names are from that function)
extern int* gTable_69c40;
class CCondition {
  public:
    virtual int vfunc_0(int);
};
class CAutoTargetTrack : public CCondition {
  public:
    int vfunc_0(int);
};
int CAutoTargetTrack::vfunc_0(int index) {
    int* p = gTable_69c40;
    return p[index];
}

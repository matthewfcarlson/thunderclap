// Same code shape as 0x00048300 (propagated; names are from that function)
extern int* gTable_60520;
class CCondition {
  public:
    virtual int vfunc_0(int);
};
class CMotionTrailTrack : public CCondition {
  public:
    int vfunc_0(int);
};
int CMotionTrailTrack::vfunc_0(int index) {
    int* p = gTable_60520;
    return p[index];
}

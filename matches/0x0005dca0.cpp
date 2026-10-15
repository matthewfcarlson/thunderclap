// Same code shape as 0x00048300 (propagated; names are from that function)
extern int* gTable_5dca0;
class CCondition {
  public:
    virtual int vfunc_0(int);
};
class CProceduralDurationAnimationTrack : public CCondition {
  public:
    int vfunc_0(int);
};
int CProceduralDurationAnimationTrack::vfunc_0(int index) {
    int* p = gTable_5dca0;
    return p[index];
}

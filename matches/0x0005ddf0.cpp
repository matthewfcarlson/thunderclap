// Same code shape as 0x00048300 (propagated; names are from that function)
extern int* gTable_5ddf0;
class CCondition {
  public:
    virtual int vfunc_0(int);
};
class CStunAnimationTrack : public CCondition {
  public:
    int vfunc_0(int);
};
int CStunAnimationTrack::vfunc_0(int index) {
    int* p = gTable_5ddf0;
    return p[index];
}

// Same code shape as 0x00048300 (propagated; names are from that function)
extern int* gTable_6ac10;
class CCondition {
  public:
    virtual int vfunc_0(int);
};
class CHeadTrackerTrack : public CCondition {
  public:
    int vfunc_0(int);
};
int CHeadTrackerTrack::vfunc_0(int index) {
    int* p = gTable_6ac10;
    return p[index];
}

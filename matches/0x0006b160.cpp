// Same code shape as 0x00048300 (propagated; names are from that function)
extern int* gTable_6b160;
class CCondition {
  public:
    virtual int vfunc_0(int);
};
class CWallSlideTrack : public CCondition {
  public:
    int vfunc_0(int);
};
int CWallSlideTrack::vfunc_0(int index) {
    int* p = gTable_6b160;
    return p[index];
}

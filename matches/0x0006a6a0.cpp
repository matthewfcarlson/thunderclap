// Same code shape as 0x00048300 (propagated; names are from that function)
extern int* gTable_6a6a0;
class CCondition {
  public:
    virtual int vfunc_0(int);
};
class COrientTrack : public CCondition {
  public:
    int vfunc_0(int);
};
int COrientTrack::vfunc_0(int index) {
    int* p = gTable_6a6a0;
    return p[index];
}

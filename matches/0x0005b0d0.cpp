// Same code shape as 0x00048300 (propagated; names are from that function)
extern int* gTable_5b0d0;
class CCondition {
  public:
    virtual int vfunc_0(int);
};
class CGrabTrack : public CCondition {
  public:
    int vfunc_0(int);
};
int CGrabTrack::vfunc_0(int index) {
    int* p = gTable_5b0d0;
    return p[index];
}

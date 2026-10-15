// Same code shape as 0x00048300 (propagated; names are from that function)
extern int* gTable_6a8b0;
class CCondition {
  public:
    virtual int vfunc_0(int);
};
class CUninterruptibleTrack : public CCondition {
  public:
    int vfunc_0(int);
};
int CUninterruptibleTrack::vfunc_0(int index) {
    int* p = gTable_6a8b0;
    return p[index];
}

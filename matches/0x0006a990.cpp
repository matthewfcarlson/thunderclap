// Same code shape as 0x00048300 (propagated; names are from that function)
extern int* gTable_6a990;
class CCondition {
  public:
    virtual int vfunc_0(int);
};
class CInvulnerableTrack : public CCondition {
  public:
    int vfunc_0(int);
};
int CInvulnerableTrack::vfunc_0(int index) {
    int* p = gTable_6a990;
    return p[index];
}

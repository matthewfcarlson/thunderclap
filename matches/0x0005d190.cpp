// Same code shape as 0x00048300 (propagated; names are from that function)
extern int* gTable_5d190;
class CCondition {
  public:
    virtual int vfunc_0(int);
};
class CHapticTrack : public CCondition {
  public:
    int vfunc_0(int);
};
int CHapticTrack::vfunc_0(int index) {
    int* p = gTable_5d190;
    return p[index];
}

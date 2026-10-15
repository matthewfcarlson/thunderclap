// Same code shape as 0x00048300 (propagated; names are from that function)
extern int* gTable_77f30;
class CCondition {
  public:
    virtual int vfunc_0(int);
};
class CHeliDeathSpiralTrack : public CCondition {
  public:
    int vfunc_0(int);
};
int CHeliDeathSpiralTrack::vfunc_0(int index) {
    int* p = gTable_77f30;
    return p[index];
}

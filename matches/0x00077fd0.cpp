// Same code shape as 0x00048300 (propagated; names are from that function)
extern int* gTable_77fd0;
class CCondition {
  public:
    virtual int vfunc_0(int);
};
class CExplosionTrack : public CCondition {
  public:
    int vfunc_0(int);
};
int CExplosionTrack::vfunc_0(int index) {
    int* p = gTable_77fd0;
    return p[index];
}

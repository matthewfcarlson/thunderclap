// Same code shape as 0x00048300 (propagated; names are from that function)
extern int* gTable_5af20;
class CCondition {
  public:
    virtual int vfunc_0(int);
};
class CGrappleSequenceTrack : public CCondition {
  public:
    int vfunc_0(int);
};
int CGrappleSequenceTrack::vfunc_0(int index) {
    int* p = gTable_5af20;
    return p[index];
}

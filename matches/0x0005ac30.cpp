// Same code shape as 0x00048300 (propagated; names are from that function)
extern int* gTable_5ac30;
class CCondition {
  public:
    virtual int vfunc_0(int);
};
class CGrappleDetachTrack : public CCondition {
  public:
    int vfunc_0(int);
};
int CGrappleDetachTrack::vfunc_0(int index) {
    int* p = gTable_5ac30;
    return p[index];
}

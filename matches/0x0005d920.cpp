// Same code shape as 0x00048300 (propagated; names are from that function)
extern int* gTable_5d920;
class CCondition {
  public:
    virtual int vfunc_0(int);
};
class CCollisionTrack : public CCondition {
  public:
    int vfunc_0(int);
};
int CCollisionTrack::vfunc_0(int index) {
    int* p = gTable_5d920;
    return p[index];
}

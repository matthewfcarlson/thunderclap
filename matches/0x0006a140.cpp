// Same code shape as 0x00048300 (propagated; names are from that function)
extern int* gTable_6a140;
class CCondition {
  public:
    virtual int vfunc_0(int);
};
class CIntangibleTrack : public CCondition {
  public:
    int vfunc_0(int);
};
int CIntangibleTrack::vfunc_0(int index) {
    int* p = gTable_6a140;
    return p[index];
}

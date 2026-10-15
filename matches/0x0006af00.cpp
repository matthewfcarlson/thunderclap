// Same code shape as 0x00048300 (propagated; names are from that function)
extern int* gTable_6af00;
class CCondition {
  public:
    virtual int vfunc_0(int);
};
class CAIHintTrack : public CCondition {
  public:
    int vfunc_0(int);
};
int CAIHintTrack::vfunc_0(int index) {
    int* p = gTable_6af00;
    return p[index];
}

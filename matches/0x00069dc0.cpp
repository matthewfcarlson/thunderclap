// Same code shape as 0x00048300 (propagated; names are from that function)
extern int* gTable_69dc0;
class CCondition {
  public:
    virtual int vfunc_0(int);
};
class CDamageTrack : public CCondition {
  public:
    int vfunc_0(int);
};
int CDamageTrack::vfunc_0(int index) {
    int* p = gTable_69dc0;
    return p[index];
}

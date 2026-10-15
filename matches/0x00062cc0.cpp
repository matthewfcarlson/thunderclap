// Same code shape as 0x00048300 (propagated; names are from that function)
extern int* gTable_62cc0;
class CCondition {
  public:
    virtual int vfunc_0(int);
};
class CPropActorSetStateTrack : public CCondition {
  public:
    int vfunc_0(int);
};
int CPropActorSetStateTrack::vfunc_0(int index) {
    int* p = gTable_62cc0;
    return p[index];
}

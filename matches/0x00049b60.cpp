// Same code shape as 0x00048300 (propagated; names are from that function)
extern int* gTable_49b60;
class CCondition {
  public:
    virtual int vfunc_0(int);
};
class CPropActorStateCondition : public CCondition {
  public:
    int vfunc_0(int);
};
int CPropActorStateCondition::vfunc_0(int index) {
    int* p = gTable_49b60;
    return p[index];
}

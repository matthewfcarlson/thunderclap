// Same code shape as 0x00048300 (propagated; names are from that function)
extern int* gTable_4a7a0;
class CCondition {
  public:
    virtual int vfunc_0(int);
};
class CCharacterBoolCondition : public CCondition {
  public:
    int vfunc_0(int);
};
int CCharacterBoolCondition::vfunc_0(int index) {
    int* p = gTable_4a7a0;
    return p[index];
}

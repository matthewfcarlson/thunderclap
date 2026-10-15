// Same code shape as 0x00048300 (propagated; names are from that function)
extern int* gTable_49e80;
class CCondition {
  public:
    virtual int vfunc_0(int);
};
class CLuaNumberCondition : public CCondition {
  public:
    int vfunc_0(int);
};
int CLuaNumberCondition::vfunc_0(int index) {
    int* p = gTable_49e80;
    return p[index];
}

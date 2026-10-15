// Same code shape as 0x00048300 (propagated; names are from that function)
extern int* gTable_4a0d0;
class CCondition {
  public:
    virtual int vfunc_0(int);
};
class CGrappleCharacterTemplateCondition : public CCondition {
  public:
    int vfunc_0(int);
};
int CGrappleCharacterTemplateCondition::vfunc_0(int index) {
    int* p = gTable_4a0d0;
    return p[index];
}

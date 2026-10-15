// Same code shape as 0x00048300 (propagated; names are from that function)
extern int* gTable_49d90;
class CCondition {
  public:
    virtual int vfunc_0(int);
};
class CGrappleSizeCondition : public CCondition {
  public:
    int vfunc_0(int);
};
int CGrappleSizeCondition::vfunc_0(int index) {
    int* p = gTable_49d90;
    return p[index];
}

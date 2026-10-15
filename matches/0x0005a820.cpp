// Same code shape as 0x00048300 (propagated; names are from that function)
extern int* gTable_5a820;
class CCondition {
  public:
    virtual int vfunc_0(int);
};
class CGrappleLocoStrafe4Track : public CCondition {
  public:
    int vfunc_0(int);
};
int CGrappleLocoStrafe4Track::vfunc_0(int index) {
    int* p = gTable_5a820;
    return p[index];
}

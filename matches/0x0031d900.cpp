// Same code shape as 0x00234f10 (propagated; names are from that function)
class ParamValue {
  public:
    virtual void vfunc_0();
    virtual int vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
};
class ParamValueColour : public ParamValue {
  public:
    virtual void vfunc_0();
    virtual int vfunc_1();
    virtual void vfunc_5();
    virtual void vfunc_6();
};
int ParamValueColour::vfunc_1() {
    return 8;
}
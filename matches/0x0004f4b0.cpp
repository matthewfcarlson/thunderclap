class ParamValue { public: virtual void vfunc_0(); virtual int vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); };
class ParamValueVector : public ParamValue { public: virtual void vfunc_0(); virtual int vfunc_1(); virtual void vfunc_5(); };
int ParamValueVector::vfunc_1() { return 7; }
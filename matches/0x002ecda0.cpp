class SimUnits { public: virtual void f0(); virtual void f1(); virtual void f2(); virtual float vfunc_3(); };
class SimCGSValue : public SimUnits { public: float mValue; float vfunc_3(); };
float SimCGSValue::vfunc_3() { return mValue; }
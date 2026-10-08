// Same code shape as 0x0005bd60 (propagated; names are from that function)
class ParamValue { public: virtual void f0(); virtual int f1(); virtual void f2(); virtual void f3(); virtual void f4(); virtual void f5(); virtual void f6(); };
class ParamValueConditionGroup : public ParamValue { public: virtual void g0(); virtual int g1(); virtual void g3(); virtual void g4(); virtual void g5(); };
int ParamValueConditionGroup::g1() { return 11; }
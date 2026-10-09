class FEThingsBase {
public:
 virtual void f0(); virtual void f1(); virtual void f2(); virtual int f3(int); virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7(); virtual void f8(); virtual void f9(); virtual void f10(); virtual void f11(); virtual void f12(); virtual void f13(); virtual void f14(); virtual void f15(); virtual void f16(); virtual void f17(); virtual void f18(int); virtual void f19(int);
};
void FEThingsBase::f18(int x) { int r = f3(x); if (r) f19(r); }

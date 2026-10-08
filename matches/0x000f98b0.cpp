class CScriptToken { public: virtual void vfunc_0(); virtual unsigned long long vfunc_1(); virtual void vfunc_2(); };
class CTokenFloat : public CScriptToken { public: unsigned long long vfunc_1(); };
unsigned long long CTokenFloat::vfunc_1() { return 1; }
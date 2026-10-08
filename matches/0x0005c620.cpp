// Same code shape as 0x00050240 (propagated; names are from that function)
class ParamValueBranch { public: virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); };
class ParamValue {};
class ParamBranch : public ParamValueBranch, public ParamValue { public: char pad[0x10-sizeof(void*)]; void (__fastcall *fn)(void*); virtual void vfunc_6(void*); };
void ParamBranch::vfunc_6(void* p) { fn(p); }
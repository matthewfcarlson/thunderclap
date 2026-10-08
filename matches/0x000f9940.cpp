// Same code shape as 0x000f9910 (propagated; names are from that function)
typedef unsigned long long u64;
extern u64 g_value;
struct DollyScript_CScriptToken { virtual void vfunc_0(); virtual u64 vfunc_1(); virtual void vfunc_2(); };
struct DollyScript_CTokenSectionStart : DollyScript_CScriptToken { virtual u64 vfunc_1(); };
u64 DollyScript_CTokenSectionStart::vfunc_1() { return g_value; }

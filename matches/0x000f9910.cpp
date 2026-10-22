typedef unsigned long long u64_f9910;
extern u64_f9910 g_value_f9910;
struct CScriptToken_f9910 {
    virtual void vfunc_0();
    virtual u64_f9910 vfunc_1();
    virtual void vfunc_2();
};
struct CTokenSectionStart_f9910 : CScriptToken_f9910 {
    virtual u64_f9910 vfunc_1();
};
u64_f9910 CTokenSectionStart_f9910::vfunc_1() {
    return g_value_f9910;
}

// Same code shape as 0x000f9910 (propagated; names are from that function)
#include "decls/data/game/DollyScript.h"
// data: g_value_f9940 = DAT_004e0a10

typedef unsigned long long u64_f9940;
struct CScriptToken_f9940 {
    virtual void vfunc_0();
    virtual u64_f9940 vfunc_1();
    virtual void vfunc_2();
};
struct CTokenSectionEnd_f9940 : CScriptToken_f9940 {
    virtual u64_f9940 vfunc_1();
};
u64_f9940 CTokenSectionEnd_f9940::vfunc_1() {
    return (*(u64_f9940*)&DAT_004e0a10);
}

// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001db770..0x001e5f10 (kind game, layer game, confidence high), dominant class CSPManager
// (tree_prelude.h: not needed)
#include "compat/ptr.h"


// 0x001e1c60 Closure3<CSPManager,void,const_char_*,bool,float>::vfunc_2 (29 B): equivalent/0x001e1c60.cpp [isolated: conflict: Arguments; Callback; on include/gen/ and not mergeable]
// sym: ?vfunc_2@Closure3_1e1c60@fn_001e1c60@@QAEXPAX00@Z @ebae63f17a2a @w465f6f008f28 @ve82eb317d976
// STATUS: equivalent (tools/equiv.py level 3: 20002 inputs, branch coverage 0/0)
// Closure3<CSPManager,void,const_char_*,bool,float>::vfunc_2 @ 0x001e1c60
#include "gen/global.h"
#include "game/script_bind.h"

struct CSPManager_1e1c60 { void invoke(const char*, bool, float); };
struct Arguments { const char* text; bool flag; char pad[3]; float value; };
typedef void (CSPManager_1e1c60::*Callback)(const char*, bool, float);

// (script2) a plain member of a non-polymorphic record (no stand-in vftable / RTTI natively): was
// `template <> void Closure3<CSPManager, void, const char *, bool, float>::vfunc_2`.
namespace fn_001e1c60 {
struct Closure3_1e1c60 : hulk_script::FunctionGenView {
    void (::CSPManager::*f_1c)(const char *, bool, float);
    hulk_intptr f_20;
    void vfunc_2(void* __p0, void* __p1, void* __p2);
};
void Closure3_1e1c60::vfunc_2(void* __p0, void* __p1, void* __p2) { hulk_intptr unused = (hulk_intptr)__p0; Arguments * args = (Arguments *)__p1; hulk_intptr unused2 = (hulk_intptr)__p2;

    ((*(CSPManager_1e1c60 * *)&this->f_20)->*(*(Callback *)&this->f_1c))(args->text, args->flag, args->value);
}
} // namespace fn_001e1c60


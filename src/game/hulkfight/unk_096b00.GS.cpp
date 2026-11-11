// cl-flags: /GS
// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00096b00..0x00098420 (kind game, layer game, confidence low)
#include "tree_prelude.h"
#include "decls/address.h"
#define TREE_TU_BEGIN namespace fn_f1b480e8 {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f1b480e8 {} using namespace fn_f1b480e8;
#include "game/hulkfight.h"

// ---- declarations shared by the functions below
namespace fn_f1b480e8 {
extern "C" int __cdecl FUN_00267760(char*, unsigned int, const char*, ...);
extern "C" unsigned long __cdecl FUN_00345d81(const char*, char**, int);


// 0x00096d80 FUN_00096d80 (205 B): equivalent/0x00096d80.cpp
// sym: _FUN_00096d80
// STATUS: equivalent (tools/equiv.py level 3: 20004 inputs, branch coverage 6/6)
// FUN_00096d80 @ 0x00096d80
extern "C" unsigned __int64 __cdecl FUN_00096d80(const char* text)
{
    unsigned __int64 result;
    if (!text) {
        result = 0;
    } else if (text[0] == '0' && text[1] == 'x') {
        char buffer[32];
        char* end;
        FUN_00267760(buffer, 32, "%s", text);
        buffer[10] = 0;
        unsigned long high = FUN_00345d81(buffer, &end, 0);
        FUN_00267760(buffer, 32, "0x%s", text + 10);
        unsigned long low = FUN_00345d81(buffer, &end, 0);
        result = (unsigned __int64)high * 0x100000000ui64 + low;
    } else {
        result = FUN_0027b020(text);
    }
    return result;
}

} // namespace fn_f1b480e8

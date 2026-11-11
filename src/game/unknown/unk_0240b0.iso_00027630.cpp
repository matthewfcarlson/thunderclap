// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000240b0..0x0002c4f0 (kind game, layer game, confidence low)
// (tree_prelude.h: not needed)


// 0x00027630 FUN_00027630 (60 B): equivalent/0x00027630.cpp [isolated: compile error C2039: 'FUN_000fdca0' : is not a member of 'fn_f6d645d0::Result']
// sym: ?FUN_00027630@Owner@fn_fc9fc607@@QAEHH@Z @d7ff09d8c2d5 @w269f831ca027
namespace fn_fc9fc607 {} using namespace fn_fc9fc607;
namespace fn_fc9fc607 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_00027630 @ 0x00027630
typedef unsigned __int64 U64;
U64 __cdecl FUN_002672f0(int value, int zero1, int zero2);
struct Item { char padding[0x1ca0]; struct Result* result; };
struct Result { int FUN_000fdca0(); };
struct Owner { Item* FUN_00024280(unsigned int low, unsigned int high); int FUN_00027630(int value); };
int Owner::FUN_00027630(int value) {
    U64 pair = FUN_002672f0(value, 0, 0);
    Item* item = FUN_00024280((unsigned int)pair, (unsigned int)(pair >> 32));
    if (!item || !item->result) return -1;
    return item->result->FUN_000fdca0();
}
} // namespace fn_fc9fc607


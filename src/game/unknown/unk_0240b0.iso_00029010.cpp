// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000240b0..0x0002c4f0 (kind game, layer game, confidence low)
// (tree_prelude.h: not needed)


// 0x00029010 FUN_00029010 (68 B): equivalent/0x00029010.cpp [isolated: compile error C2039: 'FUN_000fdc40' : is not a member of 'fn_f6d645d0::Node']
// sym: ?FUN_00029010@Owner@fn_f3066125@@QAEHH@Z
namespace fn_f3066125 {} using namespace fn_f3066125;
namespace fn_f3066125 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_00029010 @ 0x00029010
struct Result { char pad[0x1ca0]; struct Node* node; };
struct Node { struct Entry* FUN_000fdc40(); };
struct Entry { int FUN_001035e0(); };
long long __cdecl FUN_002672f0(int value, int zero1, int zero2);
struct Owner { Result* FUN_00024280(unsigned int low, unsigned int high); int FUN_00029010(int value); };
int Owner::FUN_00029010(int value) {
    long long pair = FUN_002672f0(value, 0, 0);
    Result* result = FUN_00024280((unsigned int)pair, (unsigned int)(pair >> 32));
    if (!result || !result->node) return 0;
    Entry* entry = result->node->FUN_000fdc40();
    if (!entry) return 0;
    return entry->FUN_001035e0();
}
} // namespace fn_f3066125


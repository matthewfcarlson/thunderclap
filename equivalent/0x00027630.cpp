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
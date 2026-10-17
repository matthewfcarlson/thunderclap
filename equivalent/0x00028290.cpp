// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_00028290 @ 0x00028290
typedef unsigned __int64 U64;
U64 __cdecl FUN_002672f0(int value, int a, int b);
U64 __cdecl FUN_0027b020(int value);
struct ItemOwner {
    U64 FUN_000443c0();
};
struct Item {
    char padding[0x11c];
    ItemOwner *owner;
};
struct Context {
    Item *FUN_00024280(U64 key);
    bool FUN_00028290(int first, int second);
};
bool Context::FUN_00028290(int first, int second) {
    U64 key = FUN_002672f0(first, 0, 0);
    Item *item = FUN_00024280(key);
    if (!item || !item->owner) return false;
    U64 ownerKey = item->owner->FUN_000443c0();
    return ownerKey == FUN_0027b020(second);
}
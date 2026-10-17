// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_00028f30 @ 0x00028f30
typedef unsigned __int64 U64;
U64 __cdecl FUN_002672f0(const char *, int, int);
struct Result { char pad[0xb4]; int value; };
struct Item { char pad[0x1ca0]; struct Query *query; };
struct Query { Result *FUN_000fdc40(); };
struct Owner {
    Item *FUN_00024280(U64);
    int FUN_00028f30(const char *name);
};
int Owner::FUN_00028f30(const char *name) {
    U64 id = FUN_002672f0(name, 0, 0);
    Item *item = FUN_00024280(id);
    if (item && item->query) {
        Result *result = item->query->FUN_000fdc40();
        if (result) return result->value;
    }
    return -1;
}
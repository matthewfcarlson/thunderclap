// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_000290a0 @ 0x000290a0
struct Result { char pad[0x1ca0]; void *field; }; 
struct Item { char pad[0x12c]; int value; };
struct Action { void FUN_000fe4d0(int, int); };
long long __cdecl FUN_002672f0(int, int, int);
struct Owner { char pad[0x124]; Item *item; Result *FUN_00024280(int, int); void FUN_000290a0(int); };
void Owner::FUN_000290a0(int arg) {
    long long pair = FUN_002672f0(arg, 0, 0);
    Result *result = FUN_00024280((int)pair, (int)(pair >> 32));
    if (result && result->field && item)
        ((Action *)result->field)->FUN_000fe4d0(item->value, 1);
}
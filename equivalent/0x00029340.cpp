// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_00029340 @ 0x00029340
struct Handler { int FUN_000fdf40(int value); };
struct Result { char pad[0x1ca0]; Handler *handler; };
struct Node { char pad[0x12c]; int value; };
struct Owner { char pad[0x124]; Node *node; Result *FUN_00024280(unsigned __int64 value); int FUN_00029340(void *input); };
unsigned __int64 __cdecl FUN_002672f0(void *input, int a, int b);
int Owner::FUN_00029340(void *input) {
    unsigned __int64 key = FUN_002672f0(input, 0, 0);
    Result *result = FUN_00024280(key);
    if (!result) return 0;
    Handler *handler = result->handler;
    if (!handler) return 0;
    if (!node) return (int)handler;
    return handler->FUN_000fdf40(node->value);
}
struct Node {
    Node* next;
    char pad[0x40];
    int key;
};
extern "C" Node* DAT_0052a180 = 0;
extern "C" char DAT_0052a188[8] = {0};
typedef void(__stdcall* LockFn)(void*);
extern "C" LockFn DAT_003f2c8c;
extern "C" LockFn DAT_003f2c88;
extern "C" int __cdecl FUN_0020c14b();
extern "C" Node* __cdecl FUN_0026dbb0() {
    Node* p = DAT_0052a180;
    DAT_003f2c8c(DAT_0052a188);
    while (p != 0 && p->key != FUN_0020c14b())
        p = p->next;
    DAT_003f2c88(DAT_0052a188);
    return p;
}
struct Node {
    Node* next;
    char pad[0x40];
    int key;
};
extern "C" Node* gHead = 0;
extern "C" char gLock_26dbb0[8] = {0};
typedef void(__stdcall* LockFn)(void*);
extern "C" LockFn DAT_003f2c8c;
extern "C" LockFn DAT_003f2c88;
extern "C" int __cdecl Key();
extern "C" Node* __cdecl FUN_0026dbb0() {
    Node* p = gHead;
    DAT_003f2c8c(gLock_26dbb0);
    while (p != 0 && p->key != Key())
        p = p->next;
    DAT_003f2c88(gLock_26dbb0);
    return p;
}
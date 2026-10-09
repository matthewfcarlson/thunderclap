struct Node { Node* next; char pad[0x40]; int key; };
extern "C" Node* gHead = 0;
extern "C" char gLock[8] = {0};
typedef void (__stdcall *LockFn)(void*);
extern "C" LockFn EnterPtr = 0;
extern "C" LockFn LeavePtr = 0;
extern "C" int __cdecl Key();
extern "C" Node* __cdecl FUN_0026dbb0() {
    Node* p = gHead;
    EnterPtr(gLock);
    while (p != 0 && p->key != Key()) p = p->next;
    LeavePtr(gLock);
    return p;
}
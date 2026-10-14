typedef unsigned int U32_26d8f0;
typedef void(__stdcall* LockFn)(void*);
extern LockFn enterFn;
extern LockFn leaveFn;
extern void* gFirst_26d8f0;
extern void* gLast_26d8f0;
extern char gLock_26d8f0[];
void __cdecl Target(U32_26d8f0* node) {
    enterFn(gLock_26d8f0);
    if (gFirst_26d8f0 == 0) {
        gFirst_26d8f0 = node;
        node[1] = 0;
    } else {
        *(U32_26d8f0*)gLast_26d8f0 = (U32_26d8f0)node;
        node[1] = (U32_26d8f0)gLast_26d8f0;
    }
    gLast_26d8f0 = node;
    node[0] = 0;
    leaveFn(gLock_26d8f0);
}
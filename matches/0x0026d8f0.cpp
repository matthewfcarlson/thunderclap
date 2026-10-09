typedef unsigned int U32;
typedef void(__stdcall* LockFn)(void*);
extern LockFn enterFn;
extern LockFn leaveFn;
extern void* gFirst;
extern void* gLast;
extern char gLock[];
void __cdecl Target(U32* node) {
    enterFn(gLock);
    if (gFirst == 0) {
        gFirst = node;
        node[1] = 0;
    } else {
        *(U32*)gLast = (U32)node;
        node[1] = (U32)gLast;
    }
    gLast = node;
    node[0] = 0;
    leaveFn(gLock);
}
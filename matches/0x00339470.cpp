typedef unsigned int uint;
extern void __cdecl CopyThing(void*, void*, int);
struct Thing_339470 {
    uint* mPtr;
    int mCount;
    void* mArg;
    int mData;
};
extern void __cdecl Finish(Thing_339470*);
int* __cdecl Target(Thing_339470* p) {
    int n = (int)p->mPtr - (int)p - 12;
    if (n != 0) {
        CopyThing(p->mArg, &p->mData, n);
        p->mPtr = (uint*)&p->mData;
        ++p->mCount;
        Finish(p);
    }
    return (int*)&p->mData;
}
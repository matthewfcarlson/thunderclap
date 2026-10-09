extern void* gThing;
struct Obj {
    void* mPtr;
    short mB;
    short pad;
    short mC;
    void helper(int, int, int, int);
    Obj* fn(int, int, int);
};
Obj* Obj::fn(int a, int b, int c) {
    if (a == 0) {
        mPtr = gThing;
        short* p = (short*)((char*)gThing - 4);
        ++*p;
        mC = 0;
        mB = 2;
    } else
        helper(a, b, b, c);
    return this;
}
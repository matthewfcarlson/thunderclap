// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// Closure2<CWorldStreamManager,int,int,int>::vfunc_2 @ 0x00205eb0
struct CWorldStreamManager { int method(int, int); };
struct Arguments { int first; int second; };
struct Closure2_CWorldStreamManager_int_int_int {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(int unused, Arguments* arguments, int* result);
    char padding[0x1c - 4];
    int (CWorldStreamManager::*method)(int, int);
    CWorldStreamManager* object;
};
void Closure2_CWorldStreamManager_int_int_int::vfunc_2(int unused, Arguments* arguments, int* result) {
    int value = (object->*method)(arguments->first, arguments->second);
    if (result) *result = value;
}

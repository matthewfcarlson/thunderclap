// STATUS: equivalent (tools/equiv.py level 3: 2991 inputs, branch coverage 2/2)
// CFightParamsCollision::vfunc_4 @ 0x00059990
typedef unsigned int size_t;
void* __cdecl FUN_0008d690(unsigned int);
struct CFightParamsCollision_59990 { void FUN_00236a60(); };
struct CollisionData {
    char pad0[0x4c]; unsigned int a,b;
    char pad1[0x0c]; unsigned int c;
    char pad2[0x08]; unsigned int d,e;
    char pad3[0x10]; unsigned int f;
    void FUN_00059370(CollisionData*);
};
struct CFightParamsCollision {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual CFightParamsCollision* vfunc_4();
    unsigned int unknown4;
    unsigned int value8;
    unsigned int valueC;
    unsigned int value10;
    unsigned int unknown14;
    CollisionData data;
};
void* __cdecl operator new(size_t, void* p) { return p; }
CFightParamsCollision* CFightParamsCollision::vfunc_4() {
    CFightParamsCollision* result = (CFightParamsCollision*)FUN_0008d690(0xb0);
    if (!result) return 0;
    unsigned int savedValue = value8;
    ((CFightParamsCollision_59990*)result)->FUN_00236a60();
    new (result) CFightParamsCollision;
    result->value8 = savedValue;
    result->valueC = 0;
    result->value10 = 0;
    result->data.a = 0;
    result->data.b = 0;
    result->data.c = 0;
    result->data.d = 0;
    result->data.e = 0;
    result->data.f = 0;
    result->data.FUN_00059370(&data);
    return result;
}
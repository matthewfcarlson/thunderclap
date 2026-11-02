// STATUS: equivalent (tools/equiv.py level 3: 3072 inputs, branch coverage 20/24, incomplete)
// FUN_00244080 @ 0x00244080
struct Range_244080 {
    char pad0[0x30];
    unsigned int lo;
    unsigned int hi;
};
class Bounds_244080 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual Range_244080* v8();
    char pad04[0x18 - 4];
    unsigned int lo;
    unsigned int hi;
};
struct Key_244080 {
    unsigned int lo;
    unsigned int hi;
    unsigned int lo2;
    unsigned int hi2;
};
extern "C" int __cdecl FUN_00244080(const void * key, void * bounds_) {
    Bounds_244080 * bounds = (Bounds_244080 *)bounds_;
    if (((const Key_244080 *)key)->hi < bounds->hi)
        return -1;
    if (((const Key_244080 *)key)->hi == bounds->hi && ((const Key_244080 *)key)->lo < bounds->lo)
        return -1;
    if (((const Key_244080 *)key)->hi > bounds->hi)
        return 1;
    if (((const Key_244080 *)key)->lo > bounds->lo)
        return 1;
    Range_244080* r = bounds->v8();
    if (((const Key_244080 *)key)->hi2 > r->hi)
        return 1;
    if (((const Key_244080 *)key)->hi2 < r->hi)
        return -1;
    if (((const Key_244080 *)key)->lo2 < r->lo)
        return -1;
    if (((const Key_244080 *)key)->lo2 > r->lo)
        return 1;
    return 0;
}

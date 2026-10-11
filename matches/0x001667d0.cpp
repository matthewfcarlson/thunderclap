extern "C" char DAT_00494b44[];
extern "C" char DAT_00494b60[];
extern int __cdecl castcheck(void*, int, void*, void*, int);

struct Lvl3 {
    unsigned char third();
};
struct Lvl2 {
    Lvl3* second();
};
struct Lvl1 {
    Lvl2* first();
};

class ThinkingCondition {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual bool vfunc_6(void* a, void* p, void* c);
    unsigned char pad[8];
    unsigned char value;
};

bool ThinkingCondition::vfunc_6(void* a, void* p, void* c) {
    if (!castcheck(p, 0, (void*)((int)DAT_00494b44), (void*)((int)DAT_00494b60), 0))
        return false;
    Lvl1* q = (Lvl1*)p;
    Lvl2* r = q->first();
    Lvl3* s = r->second();
    unsigned char v = value;
    return s->third() == v;
}

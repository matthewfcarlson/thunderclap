struct Obj {
    char pad[0x1d44];
    float value;
};
struct Manager {
    char pad[0x2c];
    void* ptr;
};
extern Manager* gMgr;
struct CalcObj {
    float Calc();
};
class Foo {
  public:
    void* p;
    CalcObj* q;
    char check(Obj* o);
};
char Foo::check(Obj* o) {
    if (q && (p || (p = gMgr->ptr)) && o) {
        *(float*)&o = o->value;
        return q->Calc() >= *(float*)&o;
    }
    return 0;
}
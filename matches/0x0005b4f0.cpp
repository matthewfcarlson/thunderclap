struct Obj {
    char pad[0x104];
    int field;
};
struct ObjB {
    char pad[0x330];
    Obj* f330;
    Obj* f334;
    Obj* Get() {
        if (f334)
            return f334;
        if (f330)
            return f330;
        return 0;
    }
};
struct ObjA {
    ObjB* GetB();
};
struct Input {
    ObjA* GetA();
};
struct Result {
    Result* Init(int);
};
void* __cdecl FUN_0008d690(int);
class CGrappleIntangibleTrack {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual Result* vfunc_12(Input*);
    virtual void v13();
};
Result* CGrappleIntangibleTrack::vfunc_12(Input* p) {
    if (p) {
        ObjA* a = p->GetA();
        if (a) {
            ObjB* b = a->GetB();
            if (b) {
                Obj* x = b->Get();
                if (x) {
                    int y = x->field;
                    if (y) {
                        Result* z = (Result*)FUN_0008d690(0x20);
                        if (z)
                            return z->Init(y);
                    }
                }
            }
        }
    }
    return 0;
}
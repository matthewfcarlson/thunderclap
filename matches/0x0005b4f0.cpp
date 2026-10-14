struct Obj_5b4f0 {
    char pad[0x104];
    int field;
};
struct ObjB_5b4f0 {
    char pad[0x330];
    Obj_5b4f0* f330;
    Obj_5b4f0* f334;
    Obj_5b4f0* Get() {
        if (f334)
            return f334;
        if (f330)
            return f330;
        return 0;
    }
};
struct ObjA_5b4f0 {
    ObjB_5b4f0* GetB();
};
struct Input_5b4f0 {
    ObjA_5b4f0* GetA();
};
struct Result_5b4f0 {
    Result_5b4f0* Init(int);
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
    virtual Result_5b4f0* vfunc_12(Input_5b4f0*);
    virtual void v13();
};
Result_5b4f0* CGrappleIntangibleTrack::vfunc_12(Input_5b4f0* p) {
    if (p) {
        ObjA_5b4f0* a = p->GetA();
        if (a) {
            ObjB_5b4f0* b = a->GetB();
            if (b) {
                Obj_5b4f0* x = b->Get();
                if (x) {
                    int y = x->field;
                    if (y) {
                        Result_5b4f0* z = (Result_5b4f0*)FUN_0008d690(0x20);
                        if (z)
                            return z->Init(y);
                    }
                }
            }
        }
    }
    return 0;
}
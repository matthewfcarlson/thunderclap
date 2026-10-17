// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_0011cd70 @ 0x0011cd70
namespace hulkfight { namespace ai {
struct RefObject {
    virtual void AddRef();
    virtual void Release();
};
struct FUN_00232660 {
    FUN_00232660();
    virtual void method0();
    char padding[0x18];
};
struct StrafeRunAction : FUN_00232660 {
    void* action;
    RefObject* ref;
    int field24;
    int field28;
    int field2c;
    StrafeRunAction(void* a, RefObject* r);
    virtual void method0();
};
StrafeRunAction::StrafeRunAction(void* a, RefObject* r) : FUN_00232660() {
    action = a;
    ref = 0;
    field24 = 0;
    field28 = 1;
    field2c = 0;
    if (r) r->AddRef();
    if (ref) ref->Release();
    ref = r;
}
}}

// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_001a5e50 @ 0x001a5e50
struct RefObject { virtual void FUN_00000000(); virtual void FUN_00000001(); };
struct Base {
    virtual void FUN_00000002();
    void FUN_00232660();
};
struct Subobject { void FUN_0022b980(); };
namespace hulkfight { namespace scenario {
struct EffectAction : Base {
    virtual void FUN_00000003();
    char pad[0x18];
    unsigned int value;
    RefObject *object;
    unsigned int field24;
    unsigned int field28;
    Subobject member;
    EffectAction(unsigned int v, RefObject *p);
};
EffectAction::EffectAction(unsigned int v, RefObject *p)
    : Base((FUN_00232660(), *static_cast<Base*>(this))) {
    value = 0;
    object = 0;
    field24 = 0;
    field28 = 0;
    value = v;
    if (p) p->FUN_00000000();
    if (object) object->FUN_00000001();
    object = p;
    member.FUN_0022b980();
}
} }

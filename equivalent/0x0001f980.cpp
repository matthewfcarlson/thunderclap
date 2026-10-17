// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_0001f980 @ 0x0001f980
inline void* operator new(unsigned int, void* place) { return place; }
struct Ref { virtual void FUN_00000000(); virtual void FUN_00000001(); };
struct CAction {
    virtual void slot0();
    char pad[0x18];
    Ref* reference;
    void* data;
    void FUN_00232660();
};
struct CJumpAttackAction : CAction {
    void* field24;
    void* field28;
    void* field2c;
    void* field30;
    CJumpAttackAction* FUN_0001f980(void* value, Ref* ref);
};
CJumpAttackAction* CJumpAttackAction::FUN_0001f980(void* value, Ref* ref) {
    FUN_00232660();
    new ((CAction*)this) CAction;
    reference = 0;
    if (ref) ref->FUN_00000000();
    if (reference) reference->FUN_00000001();
    reference = ref;
    field24 = 0;
    new (this) CJumpAttackAction;
    field28 = 0;
    field2c = 0;
    field30 = 0;
    data = value;
    return this;
}
extern "C" void _ReadWriteBarrier();
extern void* g_vftable_183a60[];
class Ref_183a60 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_183a60 {
  public:
    void* vptr;
    void Fin();
};
class PropActorThinkingAction_183a60 : public Action_183a60 {
  public:
    char pad[0x18];
    void* m1c;
    Ref_183a60* m20;
    ~PropActorThinkingAction_183a60();
};
PropActorThinkingAction_183a60::~PropActorThinkingAction_183a60() {
    vptr = g_vftable_183a60;
    _ReadWriteBarrier();
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    Fin();
}

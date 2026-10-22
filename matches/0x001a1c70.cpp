extern "C" void _ReadWriteBarrier();
extern void* g_vftable_1a1c70[];
void operator delete(void*);
class Ref_1a1c70 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_1a1c70 {
  public:
    void* vptr;
    void Fin();
};
class LuaAction_1a1c70 : public Action_1a1c70 {
  public:
    char pad[28];
    Ref_1a1c70* m;
    LuaAction_1a1c70* f2(unsigned char flags);
};
LuaAction_1a1c70* LuaAction_1a1c70::f2(unsigned char flags) {
    vptr = g_vftable_1a1c70;
    _ReadWriteBarrier();
    if (m) {
        m->Release();
        m = 0;
    }
    Fin();
    if (flags & 1)
        operator delete(this);
    return this;
}

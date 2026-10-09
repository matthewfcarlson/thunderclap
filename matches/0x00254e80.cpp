class SeqEvent { public: bool vfunc_0(void*); };
class SeqEventContainer { public: bool vfunc_0(void*); };
extern bool FUN_0025ac10(void*, void*);
class SeqEventLogicOr {
public:
    virtual int vfunc_0(void* arg);
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    char pad[0x14 - 4];
};
int SeqEventLogicOr::vfunc_0(void* arg) {
    if (((SeqEvent*)this)->vfunc_0(arg) && FUN_0025ac10(arg, (char*)this + 0x14) && ((SeqEventContainer*)this)->vfunc_0(arg))
        return 1;
    return 0;
}

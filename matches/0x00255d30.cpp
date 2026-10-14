class SeqEvent {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    char pad[4];
};
extern bool __cdecl FUN_0025aa80(void*, void*);
class Sub_255d30 {
  public:
    bool run(void*);
};
class SeqEventClip : public SeqEvent {
  public:
    virtual int vfunc_0(void*);
};
int SeqEventClip::vfunc_0(void* param) {
    if ((char)SeqEvent::vfunc_0(param)) {
        if (FUN_0025aa80(param, (char*)this + 8)) {
            if (((Sub_255d30*)((char*)this + 0x10))->run(param)) {
                return 1;
            }
        }
    }
    return 0;
}

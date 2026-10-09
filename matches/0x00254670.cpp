// Same code shape as 0x002523a0 (propagated; names are from that function)
class SeqEvent {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
};
bool FUN_0025ac10(void*, void*);
class SeqEventVarVolumeRand : public SeqEvent {
  public:
    char pad[8];
    int x;
    int y;
    int vfunc_0(void* p);
};
int SeqEventVarVolumeRand::vfunc_0(void* p) {
    char r = (char)SeqEvent::vfunc_0(p);
    if (r) {
        if (FUN_0025ac10(p, (char*)this + 8)) {
            if (FUN_0025ac10(p, (char*)this + 12))
                return 1;
        }
    }
    return 0;
}

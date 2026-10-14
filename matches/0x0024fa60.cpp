namespace audio {
class SeqAction {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
};
extern void Init(void*, void*);
extern int baseVtable;
class SeqActionChannelSends : public SeqAction {
  public:
    virtual SeqActionChannelSends* vfunc_0(int);
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
};
} // namespace audio
extern char gData_24fa60[];
audio::SeqActionChannelSends* audio::SeqActionChannelSends::vfunc_0(int x) {
    *(unsigned long*)this = (unsigned long)&baseVtable;
    if (x & 1)
        Init(gData_24fa60, this);
    return this;
}
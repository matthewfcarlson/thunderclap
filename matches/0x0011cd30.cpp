extern "C" void __cdecl opdel1(void*);
extern "C" void __cdecl opdel2(void*);
extern const char PathTrack_vftable[];

class M40 {
  public:
    ~M40();
};

class PathTrack {
  public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual PathTrack* vfunc_5(int flag);
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    void BaseDtor();
};

PathTrack* PathTrack::vfunc_5(int flag) {
    *(void**)this = (void*)PathTrack_vftable;
    opdel1(*(void**)((char*)this + 0x38));
    ((M40*)((char*)this + 0x40))->~M40();
    this->BaseDtor();
    if (flag & 1) {
        opdel2((void*)this);
    }
    return this;
}

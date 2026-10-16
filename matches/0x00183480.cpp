extern "C" void __cdecl thunk_FUN_00267090(void*);
extern "C" void __cdecl thunk_FUN_00267090_2(void*);
extern char PropSpawnTrack_vftable;

class SubObj_183480 {
  public:
    void Reset();
};

namespace hulkfight { namespace motion { class PropSpawnTrack {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void* vfunc_5(unsigned char param);
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void vfunc_10();

    void DoSomething();

    void* vftable_;
    char pad_04[0x0c];
    void* field_10;
    char pad_14[0x04];
}; }}

void* hulkfight::motion::PropSpawnTrack::vfunc_5(unsigned char param) {
    void* m = *(void**)((char*)this + 0x10);
    *(void**)this = (void*)&PropSpawnTrack_vftable;
    thunk_FUN_00267090(m);
    ((SubObj_183480*)((char*)this + 0x18))->Reset();
    this->DoSomething();
    if (param & 1) {
        thunk_FUN_00267090_2(this);
    }
    return this;
}

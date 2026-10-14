struct Mgr {
    void Set(int n);
};

struct Owner {
    char pad[4];
    Mgr* mgr;
};

extern Owner* gOwner;

class CSoundCommand {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1(int a, int b);
};

class CSoundCommand_ReturnToDefaultMix : public CSoundCommand {
  public:
    char pad[0xc];
    float mValue;
    virtual void vfunc_1(int a, int b);
};

void CSoundCommand_ReturnToDefaultMix::vfunc_1(int a, int b) {
    gOwner->mgr->Set((int)mValue);
}

extern "C" void _ReadWriteBarrier();
class Thing {
  public:
    virtual void Use();
};
class Str {
  public:
    Thing* Find();
};
class AgentBase {
  public:
    virtual void Init();
    AgentBase(const char*);
};
class OccupationAgent : public AgentBase {
  public:
    virtual void Own();
    char pad04[0x58];
    Thing* m5c;
    int m60;
    unsigned char m64;
    char pad65[0x3f];
    unsigned char mA4, mA5;
    char pA6[2];
    int mA8, mAC, mB0, mB4, mB8;
    float mBC;
    unsigned char mC0;
    char pC1[3];
    float mC4;
    unsigned char mC8;
    char pC9[3];
    int mCC, mD0, mD4, mD8, mDC, mE0, mE4, mE8, mEC;
    OccupationAgent(const char*);
};
OccupationAgent::OccupationAgent(const char* name) : AgentBase(name) {
    m60 = 0;
    _ReadWriteBarrier();
    mA4 = 1;
    mA5 = 0;
    mA8 = 0;
    mAC = 0;
    mB0 = 0;
    mB4 = -1;
    mB8 = 0;
    mC0 = 0;
    mC8 = 0;
    _ReadWriteBarrier();
    mBC = 1.0f;
    mC4 = 1.0f;
    mCC = 0;
    mD0 = 0;
    mD4 = 0;
    mD8 = 0;
    mDC = 0;
    mE0 = 0;
    mE4 = 0;
    mE8 = 0;
    _ReadWriteBarrier();
    mEC = 0;
    m64 = 0;
    Thing* t = ((Str*)name)->Find();
    m5c = t;
    t->Use();
}

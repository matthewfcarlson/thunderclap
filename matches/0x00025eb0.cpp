extern void __fastcall InitThing(void*);
extern int gValue;
class Thing {
  public:
    char pad000[4];
    void* mChild;
    char pad008[0x48];
    unsigned char mFlag50;
    char pad051[0x83];
    int mA;
    int mB;
    int mC;
    char pad0e0[0x270];
    unsigned char m350;
    unsigned char m351;
    unsigned char m352;
    char pad353[0x231];
    int m584;
    unsigned char m588;
    void Run();
};
void Thing::Run() {
    mFlag50 = 1;
    mA = 4;
    mB = 3;
    mC = 1;
    InitThing(mChild);
    m350 = 0;
    m351 = 0;
    m352 = 1;
    gValue = 0x41000000;
    m584 = 0x7fffffff;
    m588 = 0;
}
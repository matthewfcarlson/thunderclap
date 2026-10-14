extern "C" char DAT_003f6098[];
extern "C" char DAT_0043147c[];
typedef unsigned int u32_2f3c00;
extern void ReleaseThing(u32_2f3c00);
class Other_2f3c00 {
  public:
    void Do(int);
};
class SharedData {
  public:
    u32_2f3c00 vft;
    u32_2f3c00 pad;
    u32_2f3c00 a;
    u32_2f3c00 b;
    u32_2f3c00 c;
    u32_2f3c00 d;
    Other_2f3c00* e;
};
void __fastcall FUN_002f3c00(SharedData* p) {
    p->vft = ((int)DAT_0043147c);
    if (p->a)
        ReleaseThing(p->a);
    if (p->b)
        ReleaseThing(p->b);
    if (p->c)
        ReleaseThing(p->c);
    if (p->d)
        ReleaseThing(p->d);
    if (p->e)
        p->e->Do(3);
    p->vft = ((int)DAT_003f6098);
}
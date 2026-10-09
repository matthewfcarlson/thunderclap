typedef unsigned int u32;
extern void ReleaseThing(u32);
class Other {
  public:
    void Do(int);
};
class SharedData {
  public:
    u32 vft;
    u32 pad;
    u32 a;
    u32 b;
    u32 c;
    u32 d;
    Other* e;
};
void __fastcall FUN_002f3c00(SharedData* p) {
    p->vft = 0x43147c;
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
    p->vft = 0x3f6098;
}
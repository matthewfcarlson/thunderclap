class CTrack_5ab30 {
  public:
    CTrack_5ab30();
    virtual void V();
    char pad[8];
};
class Part {
  public:
    Part();
    char pad[8];
};
class CGrappleSwapTrack_5ab30 : public CTrack_5ab30 {
  public:
    CGrappleSwapTrack_5ab30();
    int a;
    Part p;
    Part q;
    volatile char flag;
    char pad2[3];
    volatile int b, c, d, e;
    int f, g;
    virtual void V();
};
CGrappleSwapTrack_5ab30::CGrappleSwapTrack_5ab30() : a(0), flag(1), b(0), c(0), d(0), e(0), f(-10), g(0) {}
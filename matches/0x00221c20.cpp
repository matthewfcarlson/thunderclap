class Base_221c20 {
  public:
    void Init();
};
class Thing_221c20 : public Base_221c20 {
    char pad[0x40];
    volatile int a;
    volatile int b;
    volatile int c;
    volatile int d;
    volatile int e;

  public:
    void Run();
};
void Thing_221c20::Run() {
    Init();
    c = 0;
    b = 0;
    a = 0;
    d = 0x3f800000;
    e = 0;
}
// Same code shape as 0x00221c20 (propagated; names are from that function)
class Base_30f0e0 {
  public:
    void Init();
};
class Thing_30f0e0 : public Base_30f0e0 {
    char pad[0x40];
    volatile int a;
    volatile int b;
    volatile int c;
    volatile int d;
    volatile int e;

  public:
    void Run();
};
void Thing_30f0e0::Run() {
    Init();
    c = 0;
    b = 0;
    a = 0;
    d = 0x3f800000;
    e = 0;
}
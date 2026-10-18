// Same code shape as 0x001c4010 (propagated; names are from that function)
class Engine_1c4050 {
  public:
    void Init(void*, int, int, int, int);
    int Finish(int);
};
class Thing_1c4050 {
  public:
    char pad[0x5c];
    int a;
    int b;
    int c;
    int d;
    char done;
    int Run(int);
};
int Thing_1c4050::Run(int x) {
    if (!done) {
        (*(Engine_1c4050**)pad)->Init(pad + 0x1c, a, b, c, d);
        done = 1;
    }
    return (*(Engine_1c4050**)pad)->Finish(x);
}
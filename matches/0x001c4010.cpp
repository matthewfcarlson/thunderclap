class Engine_1c4010 {
  public:
    void Init(void*, int, int, int, int);
    void Finish(int);
};
class Thing_1c4010 {
  public:
    char pad[0x5c];
    int a;
    int b;
    int c;
    int d;
    char done;
    void Run(int);
};
void Thing_1c4010::Run(int x) {
    if (!done) {
        (*(Engine_1c4010**)pad)->Init(pad + 0x1c, a, b, c, d);
        done = 1;
    }
    (*(Engine_1c4010**)pad)->Finish(x);
}
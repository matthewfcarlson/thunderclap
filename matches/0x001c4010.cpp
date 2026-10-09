class Engine {
  public:
    void Init(void*, int, int, int, int);
    void Finish(int);
};
class Thing {
  public:
    char pad[0x5c];
    int a;
    int b;
    int c;
    int d;
    char done;
    void Run(int);
};
void Thing::Run(int x) {
    if (!done) {
        (*(Engine**)pad)->Init(pad + 0x1c, a, b, c, d);
        done = 1;
    }
    (*(Engine**)pad)->Finish(x);
}
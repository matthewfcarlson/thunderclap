class Inner {
  public:
    void Step();
};
extern "C" void Finish();
class Obj {
    char pad[4];

  public:
    Inner* inner;
    int Run(int a, int b);
};
int Obj::Run(int a, int b) {
    if (!inner)
        return -1;
    inner->Step();
    Finish();
    return 0;
}
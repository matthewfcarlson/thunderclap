extern "C" char DAT_0042ae9c[];
class LoadStream {
  public:
    int vtable;
    int field4;
    char pad[5];
    unsigned char flagD;
    unsigned char flagE;
    void Init();
    void Setup(int);
    LoadStream* Target(int, int, int);
};
LoadStream* LoadStream::Target(int a, int b, int c) {
    field4 = 0;
    vtable = ((int)DAT_0042ae9c);
    Init();
    flagD = 1;
    flagE = (c == 1);
    Setup(a);
    return this;
}
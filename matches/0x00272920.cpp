class Sub_272920 {
  public:
    virtual void Begin();
    virtual void End();
};
int FUN_0026dbb0();
class Owner_272920 {
  public:
    char pad0[12];
    Sub_272920 sub;
    char pad10[0x30];
    int state;
    char pad44[4];
    int value;
    int arg1;
    int arg2;
    void Run(int a, int b);
};
void Owner_272920::Run(int a, int b) {
    sub.Begin();
    value = FUN_0026dbb0();
    arg1 = a;
    arg2 = b;
    state = 2;
    sub.End();
}
extern "C" void __cdecl FUN_00246ab0();
extern "C" void __cdecl FUN_00246b00();
extern "C" void __cdecl FUN_00246b50();
extern "C" void __cdecl FUN_00246b70();
extern "C" void __cdecl FUN_00246b90();
extern "C" char DAT_00429224[];
class MemoryStream {
  public:
    int vp;
    void (*p1)();
    void (*p2)();
    void (*p3)();
    void (*p4)();
    void (*p5)();
    unsigned char b18;
    char pad[3];
    int x1;
    int x2;
    int x3;
    unsigned char flag;
    MemoryStream(int a, int b, unsigned char c);
};
MemoryStream::MemoryStream(int a, int b, unsigned char c) {
    x1 = b;
    p1 = FUN_00246ab0;
    p2 = FUN_00246b00;
    p3 = FUN_00246b50;
    p4 = FUN_00246b70;
    p5 = FUN_00246b90;
    b18 = 0;
    vp = ((int)DAT_00429224);
    x2 = a;
    x3 = a;
    flag = c;
}

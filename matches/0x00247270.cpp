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
    p1 = (void (*)())0x246ab0;
    p2 = (void (*)())0x246b00;
    p3 = (void (*)())0x246b50;
    p4 = (void (*)())0x246b70;
    p5 = (void (*)())0x246b90;
    b18 = 0;
    vp = 0x429224;
    x2 = a;
    x3 = a;
    flag = c;
}

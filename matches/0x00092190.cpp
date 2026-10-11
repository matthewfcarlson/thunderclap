extern void* gB[];
extern void* gM[];
struct S {
    int a, b;
    void Init();
};
class Mov {
  public:
    void* vptr;
    char pad[4];
    unsigned char m8;
    char pad2[7];
    S s10;
    int m18;
    char pad3[4];
    unsigned char m20;
    int m24;
    unsigned char m28;
    char pad4[7];
    unsigned char m30;
    Mov* ctor();
};
Mov* Mov::ctor() {
    vptr = gB;
    m8 = 1;
    s10.Init();
    m18 = 0;
    m20 = 0;
    m28 = 0;
    m30 = 0;
    m24 = -1;
    vptr = gM;
    return this;
}

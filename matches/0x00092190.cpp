extern void* gB_92190[];
extern void* gM[];
struct S_92190 {
    int a, b;
    void Init();
};
class CUnlockableMovie_92190 {
  public:
    void* vptr;
    char pad[4];
    unsigned char m8;
    char pad2[7];
    S_92190 s10;
    int m18;
    char pad3[4];
    unsigned char m20;
    int m24;
    unsigned char m28;
    char pad4[7];
    unsigned char m30;
    CUnlockableMovie_92190* ctor();
};
CUnlockableMovie_92190* CUnlockableMovie_92190::ctor() {
    vptr = gB_92190;
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

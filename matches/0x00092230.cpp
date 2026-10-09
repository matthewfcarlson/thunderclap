class Sub {
  public:
    void Init();
};
class CUnlockableGallery {
  public:
    unsigned long v;
    char pad4[4];
    unsigned char flag;
    char pad9[7];
    char at10[8];
    unsigned long m18;
    char pad1c[4];
    unsigned long m20;
    char pad24[0x80];
    char atA4[4];
    char atA8[8];
    unsigned char mB0;
    char padB1[0x13];
    unsigned char mC4;
    char padC5[0x3f];
    unsigned char m104;
};
CUnlockableGallery* __fastcall FUN_00092230(CUnlockableGallery* p) {
    p->v = 0x40449c;
    p->flag = 1;
    ((Sub*)((char*)p + 0x10))->Init();
    p->m18 = 0;
    p->v = 0x4044cc;
    p->m20 = 0;
    ((Sub*)((char*)p + 0xa8))->Init();
    p->mB0 = 0;
    *((unsigned char*)p + 0x24) = 0;
    *((unsigned char*)p + 0x64) = 0;
    return p;
}
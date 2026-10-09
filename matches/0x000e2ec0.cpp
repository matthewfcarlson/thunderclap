extern "C" void* memcpy(void*, const void*, unsigned int);
class Obj {
  public:
    char p0[0x78];
    unsigned int f78, f7c, f80;
    char p84[0x94];
    unsigned int f118[10];
    unsigned int f140, f144, f148, f14c, f150, f154, f158, f15c, f160, f164, f168;
    char p16c[0x10];
    unsigned int f17c;
    void Init(Obj*);
    void Copy(Obj*);
};
void Obj::Copy(Obj* src) {
    Init(src);
    memcpy(f118, src->f118, 40);
    f158 = src->f158;
    f15c = src->f15c;
    f160 = src->f160;
    f164 = src->f164;
    f150 = src->f150;
    f168 = src->f168;
    f78 = src->f78;
    f7c = src->f7c;
    f80 = src->f80;
    f17c = src->f17c;
}
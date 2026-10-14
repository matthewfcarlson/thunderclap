class Obj_e03c0 {
  public:
    char pad[0x1840];
    unsigned a;
    unsigned b;
    unsigned c;
    unsigned char flag;
    void Set(unsigned x, unsigned y, unsigned z, unsigned w, unsigned v);
};
void Obj_e03c0::Set(unsigned x, unsigned y, unsigned z, unsigned w, unsigned v) {
    a = x;
    b = y;
    flag = 1;
    c = ((z | 0xffffff00) << 8 | w) << 8 | v;
}
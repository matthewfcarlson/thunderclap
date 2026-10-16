class Obj {
  public:
    char pad[16];
    unsigned short a, b, c, d;
    Obj(unsigned short x, unsigned short y, unsigned short z);
};
Obj::Obj(unsigned short x, unsigned short y, unsigned short z) {
    a = x;
    b = y;
    c = z;
    d = 7;
}
class Obj {
    char pad[0x194];

  public:
    unsigned char flag;
};
struct ThisWrap_001df350 {
    Obj* lookup(int);
    unsigned char FUN_001df350(int id);
};
unsigned char ThisWrap_001df350::FUN_001df350(int id) {
    Obj* p = this->lookup(id);
    unsigned char r = 0;
    if (p)
        r = p->flag;
    return r;
}
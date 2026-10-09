class Obj {
  public:
    char pad[0x9c];
    unsigned a, b, c;
    void Set(unsigned* p, unsigned v);
};
void Obj::Set(unsigned* p, unsigned v) {
    a = *p;
    b = v;
    unsigned* q = &b;
    c = *q;
}
class Obj_1c4ac0 {
  public:
    char pad[0x9c];
    unsigned a, b, c;
    void Set(unsigned* p, unsigned v);
};
void Obj_1c4ac0::Set(unsigned* p, unsigned v) {
    a = *p;
    b = v;
    unsigned* q = &b;
    c = *q;
}
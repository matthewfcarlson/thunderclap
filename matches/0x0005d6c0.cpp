struct Src_5d6c0 {
    int a, b, c;
};
class Owner_5d6c0 {
  public:
    char pad[0x20];
    Src_5d6c0 data;
    bool Set(Src_5d6c0* p);
};
bool Owner_5d6c0::Set(Src_5d6c0* p) {
    data.a = p->a;
    data.b = p->b;
    data.c = p->c;
    return true;
}

struct Src {
    int a, b, c;
};
class Owner {
  public:
    char pad[0x20];
    Src data;
    bool Set(Src* p);
};
bool Owner::Set(Src* p) {
    data.a = p->a;
    data.b = p->b;
    data.c = p->c;
    return true;
}

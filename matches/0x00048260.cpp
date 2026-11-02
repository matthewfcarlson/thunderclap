class C {
  public:
    C* First();
    C* Second();
    char pad[0x330];
    int a;
    int b;
    int c;
};
extern "C" int FUN_00048260(C* p) {
    if (!p)
        return 0;
    C* q = p->First()->Second();
    int r = q->b;
    if (!r)
        r = q->a;
    if (!r)
        r = q->c;
    return r;
}
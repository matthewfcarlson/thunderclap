struct S {
    int a, b, c;
};
class C {
  public:
    char Pad[0x38];
    int v38;
    int v3c;
    int v40;
    char Set(S* p);
};
char C::Set(S* p) {
    S* q = p;
    v38 = q->a;
    v3c = q->b;
    v40 = q->c;
    return 1;
}
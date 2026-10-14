struct S {
    int a;
    int b;
    int c;
};
class T {
  public:
    char pad[0x44];
    int m44;
    int m48;
    int m4c;
    char Fn(S* p);
};
char T::Fn(S* p) {
    m44 = p->a;
    m48 = p->b;
    m4c = p->c;
    return 1;
}

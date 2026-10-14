struct S_192910 {
    int a;
    int b;
    int c;
};
class T_192910 {
  public:
    char pad[0x44];
    int m44;
    int m48;
    int m4c;
    char Fn(S_192910* p);
};
char T_192910::Fn(S_192910* p) {
    m44 = p->a;
    m48 = p->b;
    m4c = p->c;
    return 1;
}

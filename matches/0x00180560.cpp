struct T_180560 {
    int a;
    int b;
    int c;
};

class O_180560 {
  public:
    char pad[0x44];
    int m44;
    int m48;
    int m4c;
    bool Set(T_180560* p);
};

bool O_180560::Set(T_180560* p) {
    m44 = p->a;
    m48 = p->b;
    m4c = p->c;
    return true;
}

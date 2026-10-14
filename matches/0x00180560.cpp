struct T {
    int a;
    int b;
    int c;
};

class O {
  public:
    char pad[0x44];
    int m44;
    int m48;
    int m4c;
    bool Set(T* p);
};

bool O::Set(T* p) {
    m44 = p->a;
    m48 = p->b;
    m4c = p->c;
    return true;
}

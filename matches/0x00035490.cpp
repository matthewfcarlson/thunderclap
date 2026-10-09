class Obj {
    char pad[0xa8];
    unsigned a, b, c;

  public:
    bool Set(unsigned* p);
};
bool Obj::Set(unsigned* p) {
    a = p[0];
    b = p[1];
    c = p[2];
    return true;
}
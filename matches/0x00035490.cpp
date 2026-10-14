class Obj_35490 {
    char pad[0xa8];
    unsigned a, b, c;

  public:
    bool Set(unsigned* p);
};
bool Obj_35490::Set(unsigned* p) {
    a = p[0];
    b = p[1];
    c = p[2];
    return true;
}
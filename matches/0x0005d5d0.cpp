class Obj {
  public:
    char pad[0xc0];
    int a, b, c;
    bool Fn(int* p);
};

bool Obj::Fn(int* p) {
    a = p[0];
    b = p[1];
    c = p[2];
    return true;
}

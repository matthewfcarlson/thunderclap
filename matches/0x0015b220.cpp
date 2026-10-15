class Obj {
  public:
    char pad[0xac];
    int a;
    int b;
    int c;
    bool Set(int* p);
};

bool Obj::Set(int* p) {
    a = p[0];
    b = p[1];
    c = p[2];
    return true;
}

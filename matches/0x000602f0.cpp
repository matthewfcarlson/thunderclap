class Obj_602f0 {
  public:
    char pad[0x78];
    int a;
    int b;
    int c;
    bool Set(int* x);
};
bool Obj_602f0::Set(int* x) {
    a = x[0];
    b = x[1];
    c = x[2];
    return true;
}

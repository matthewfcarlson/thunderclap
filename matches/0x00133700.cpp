class Obj_133700 {
  public:
    char pad[0x18];
    int a;
    int b;
    int c;
    bool Set(int* x);
};
bool Obj_133700::Set(int* x) {
    a = x[0];
    b = x[1];
    c = x[2];
    return true;
}

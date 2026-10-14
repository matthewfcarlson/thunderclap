class Obj {
  public:
    char pad[0xc];
    bool Set(int v);
};

bool Obj::Set(int v) {
    *((int*)pad + 3) = v;
    return true;
}
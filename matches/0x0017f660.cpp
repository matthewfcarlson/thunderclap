class Obj_17f660 {
  public:
    char pad[0xc];
    bool Set(int v);
};

bool Obj_17f660::Set(int v) {
    *((int*)pad + 3) = v;
    return true;
}
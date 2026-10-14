class Obj_68380 {
  public:
    char pad[0x18];
    int m18;
    bool Set(int v);
};

bool Obj_68380::Set(int v) {
    m18 = v;
    return true;
}

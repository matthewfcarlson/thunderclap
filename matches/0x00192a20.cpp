class Obj_192a20 {
  public:
    char pad[0x68];
    int m68;
    bool Set(int v);
};

bool Obj_192a20::Set(int v) {
    m68 = v;
    return true;
}

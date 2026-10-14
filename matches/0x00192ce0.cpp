class Obj_192ce0 {
  public:
    char pad[0xec];
    int value;
    bool Set(int v);
};

bool Obj_192ce0::Set(int v) {
    value = v;
    return true;
}

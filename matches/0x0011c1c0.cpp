class Obj_11c1c0 {
  public:
    char pad[0x58];
    int value;
    bool Set(int v);
};

bool Obj_11c1c0::Set(int v) {
    value = v;
    return true;
}

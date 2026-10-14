class Obj_193980 {
  public:
    char pad[0x58];
    int value;
    bool Set(int v);
};

bool Obj_193980::Set(int v) {
    value = v;
    return true;
}

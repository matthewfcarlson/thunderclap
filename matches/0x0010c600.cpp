class Obj_10c600 {
  public:
    char pad[0xc];
    int mValue;
    bool Set(int v);
};

bool Obj_10c600::Set(int v) {
    mValue = v;
    return true;
}
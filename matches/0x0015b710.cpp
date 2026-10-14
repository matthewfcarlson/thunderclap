class Obj_15b710 {
  public:
    char pad[0x40];
    int mValue;
    bool Set(int v);
};

bool Obj_15b710::Set(int v) {
    mValue = v;
    return true;
}

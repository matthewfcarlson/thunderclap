class Obj_16f080 {
  public:
    char pad[0x60];
    int mValue;
    bool Set(int v);
};

bool Obj_16f080::Set(int v) {
    mValue = v;
    return true;
}

class Obj_12e180 {
  public:
    char pad[0xc];
    int mValue;
    bool Set(int v);
};

bool Obj_12e180::Set(int v) {
    mValue = v;
    return true;
}
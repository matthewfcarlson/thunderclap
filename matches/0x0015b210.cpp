class Obj_15b210 {
  public:
    char pad[0xa8];
    int mValue;
    bool Set(int v);
};

bool Obj_15b210::Set(int v) {
    mValue = v;
    return true;
}
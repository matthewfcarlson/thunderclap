class Obj_48110 {
  public:
    char pad[12];
    int mValue;
    bool Set(int v);
};

bool Obj_48110::Set(int v) {
    mValue = v;
    return true;
}

class Obj_16ec70 {
  public:
    bool Set(int v);
    char pad[16];
    int mValue;
};

bool Obj_16ec70::Set(int v) {
    mValue = v;
    return true;
}

class Obj_115500 {
  public:
    char pad[0x1c];
    int mValue;
    bool Set(int v);
};

bool Obj_115500::Set(int v) {
    mValue = v;
    return true;
}
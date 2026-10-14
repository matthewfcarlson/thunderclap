class Obj_15aaf0 {
  public:
    char pad[0xc];
    int mValue;
    bool Set(int v);
};

bool Obj_15aaf0::Set(int v) {
    mValue = v;
    return true;
}

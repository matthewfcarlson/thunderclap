class Obj_17f930 {
  public:
    char pad[0x14];
    int mValue;
    bool Set(int v);
};

bool Obj_17f930::Set(int v) {
    mValue = v;
    return true;
}

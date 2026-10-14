class Obj_683b0 {
  public:
    char pad[0xc];
    int mValue;
    bool Set(int v);
};

bool Obj_683b0::Set(int v) {
    mValue = v;
    return true;
}

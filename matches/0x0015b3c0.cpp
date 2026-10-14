class Obj_15b3c0 {
  public:
    char pad[0x1c];
    int mX;
    bool Set(int v);
};

bool Obj_15b3c0::Set(int v) {
    mX = v;
    return true;
}

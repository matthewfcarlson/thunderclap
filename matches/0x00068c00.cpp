class Obj_68c00 {
  public:
    char pad[0x1c];
    int mValue;
    bool Set(int v);
};

bool Obj_68c00::Set(int v) {
    mValue = v;
    return true;
}

class Obj_68810 {
  public:
    char pad[0x28];
    int mValue;
    bool Set(int v);
};

bool Obj_68810::Set(int v) {
    mValue = v;
    return true;
}

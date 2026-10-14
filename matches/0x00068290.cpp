class Obj_68290 {
  public:
    char pad[0x10];
    int mValue;
    bool Set(int v);
};

bool Obj_68290::Set(int v) {
    mValue = v;
    return true;
}
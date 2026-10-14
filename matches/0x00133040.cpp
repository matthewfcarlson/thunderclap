class Obj_133040 {
  public:
    char pad[0x14];
    int mValue;
    bool Set(int v);
};

bool Obj_133040::Set(int v) {
    mValue = v;
    return true;
}

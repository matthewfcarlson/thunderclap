class Obj_133640 {
  public:
    char pad[0x40];
    int mValue;
    bool Set(int v);
};

bool Obj_133640::Set(int v) {
    mValue = v;
    return true;
}

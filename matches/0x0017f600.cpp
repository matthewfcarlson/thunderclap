class Obj_17f600 {
  public:
    char pad[12];
    int mValue;
    bool Set(int v);
};
bool Obj_17f600::Set(int v) {
    mValue = v;
    return true;
}
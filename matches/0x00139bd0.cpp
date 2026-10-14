class Obj_139bd0 {
  public:
    char pad[0x20];
    unsigned int mValue;
    bool Set(unsigned int v);
};
bool Obj_139bd0::Set(unsigned int v) {
    mValue = v;
    return true;
}

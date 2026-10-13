class Obj {
  public:
    char pad[0x20];
    unsigned int mValue;
    bool Set(unsigned int v);
};
bool Obj::Set(unsigned int v) {
    mValue = v;
    return true;
}

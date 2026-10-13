class Obj {
  public:
    bool Ctor(int arg);
    char pad[0xc];
    int mValue;
};
bool Obj::Ctor(int arg) {
    mValue = arg;
    return true;
}

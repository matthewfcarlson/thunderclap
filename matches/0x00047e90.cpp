class Obj {
  public:
    char pad[12];
    int mVal;
    bool Set(int arg);
};
bool Obj::Set(int arg) {
    mVal = arg;
    return true;
}
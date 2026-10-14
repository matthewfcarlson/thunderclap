class Obj {
  public:
    char pad[0x14];
    int m14;
    bool Fn(int arg);
};
bool Obj::Fn(int arg) {
    m14 = arg;
    return true;
}
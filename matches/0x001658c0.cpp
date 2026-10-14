class Obj {
  public:
    char Pad[0x38];
    int m38;
    bool Fn(int x);
};
bool Obj::Fn(int x) {
    m38 = x;
    return true;
}
class Obj {
  public:
    char pad[0xc8];
    bool Set(char c);
};
bool Obj::Set(char c) {
    pad[0xc8] = c;
    return true;
}

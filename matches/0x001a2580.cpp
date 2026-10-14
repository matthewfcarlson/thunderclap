class Obj {
  public:
    char pad[0x99];
    char m99;
    bool Set(char c);
};
bool Obj::Set(char c) {
    m99 = c;
    return true;
}

class Obj {
  public:
    char pad[0xf9];
    char mVal;
    bool Set(char c);
};

bool Obj::Set(char c) {
    mVal = c;
    return true;
}

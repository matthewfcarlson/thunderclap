class Obj_1a2880 {
  public:
    char pad[0xf9];
    char mVal;
    bool Set(char c);
};

bool Obj_1a2880::Set(char c) {
    mVal = c;
    return true;
}

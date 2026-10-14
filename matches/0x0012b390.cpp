class Obj_12b390 {
  public:
    char pad[0x18];
    char m;
    bool Set(char c);
};

bool Obj_12b390::Set(char c) {
    m = c;
    return true;
}

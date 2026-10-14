class Obj {
  public:
    char pad[0x118];
    char value;
    char Fn(char v);
};

char Obj::Fn(char v) {
    value = v;
    return 1;
}

class Obj {
  public:
    char Fn(char c);
    char pad[0x39];
    char m39;
};

char Obj::Fn(char c) {
    m39 = c;
    return 1;
}

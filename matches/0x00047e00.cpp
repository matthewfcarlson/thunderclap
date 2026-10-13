class Obj {
  public:
    char pad[0xc];
    char value;
    char Set(char c);
};

char Obj::Set(char c) {
    value = c;
    return 1;
}

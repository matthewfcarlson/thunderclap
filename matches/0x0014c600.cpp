class Obj {
  public:
    char pad[0xc];
    char value;
    char Set(char x);
};

char Obj::Set(char x) {
    value = x;
    return 1;
}

class Obj {
  public:
    char m[0xb9];
    char Set(char x);
};

char Obj::Set(char x) {
    m[0xb9] = x;
    return 1;
}

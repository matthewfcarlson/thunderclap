class Obj_17fc20 {
  public:
    char Set(char x);
    char pad[0x80];
    char m80;
};

char Obj_17fc20::Set(char x) {
    m80 = x;
    return 1;
}

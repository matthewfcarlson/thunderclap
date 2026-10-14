class Obj_47e00 {
  public:
    char pad[0xc];
    char value;
    char Set(char c);
};

char Obj_47e00::Set(char c) {
    value = c;
    return 1;
}

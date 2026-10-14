class Obj_14c600 {
  public:
    char pad[0xc];
    char value;
    char Set(char x);
};

char Obj_14c600::Set(char x) {
    value = x;
    return 1;
}

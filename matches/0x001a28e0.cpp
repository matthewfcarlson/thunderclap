class Obj_1a28e0 {
  public:
    char pad[0x108];
    char flag;
    char SetFlag(char b);
};
char Obj_1a28e0::SetFlag(char b) {
    flag = b;
    return 1;
}
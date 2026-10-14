class Obj_16f170 {
  public:
    char pad[0x10];
    int value;
    char Set(int x);
};
char Obj_16f170::Set(int x) {
    value = x;
    return 1;
}

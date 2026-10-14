class Obj_146ae0 {
  public:
    char pad[0x24];
    int value;
    char Set(int x);
};
char Obj_146ae0::Set(int x) {
    value = x;
    return 1;
}
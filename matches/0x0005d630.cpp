class Obj_5d630 {
  public:
    char Set(int x);
    char pad[0xd8];
    int value;
};
char Obj_5d630::Set(int x) {
    value = x;
    return 1;
}

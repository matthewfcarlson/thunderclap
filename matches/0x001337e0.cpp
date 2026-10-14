class Obj_1337e0 {
  public:
    char pad[0x38];
    int m38;
    char Set(int x);
};
char Obj_1337e0::Set(int x) {
    m38 = x;
    return 1;
}
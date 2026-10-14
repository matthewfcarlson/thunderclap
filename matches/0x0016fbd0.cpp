class Obj_16fbd0 {
  public:
    char pad[0x38];
    int m38;
    char Set(int a);
};
char Obj_16fbd0::Set(int a) {
    m38 = a;
    return 1;
}

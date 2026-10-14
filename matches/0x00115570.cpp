class Obj_115570 {
  public:
    char pad[0x10];
    int value;
    char Set(int a);
};

char Obj_115570::Set(int a) {
    value = a;
    return 1;
}

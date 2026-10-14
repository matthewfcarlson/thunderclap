class Obj_18f080 {
  public:
    char Set(int a);
    char pad[0x5c];
    int value;
};

char Obj_18f080::Set(int a) {
    value = a;
    return 1;
}

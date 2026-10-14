class Obj_15a820 {
  public:
    char Set(char value);
    char pad[12];
};

char Obj_15a820::Set(char value) {
    pad[12] = value;
    return 1;
}

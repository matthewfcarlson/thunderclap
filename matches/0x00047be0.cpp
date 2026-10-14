class Obj_47be0 {
  public:
    char pad[0x1c];
    int m;
    char Set(int value);
};

char Obj_47be0::Set(int value) {
    m = value;
    return 1;
}

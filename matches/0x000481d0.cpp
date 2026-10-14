class Obj_481d0 {
  public:
    char pad[0x10];
    int value;
    char Set(int x);
};

char Obj_481d0::Set(int x) {
    value = x;
    return 1;
}

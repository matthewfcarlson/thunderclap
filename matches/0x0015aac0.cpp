class Obj_15aac0 {
  public:
    char pad[0x94];
    int m94;
    char Set(int value);
};

char Obj_15aac0::Set(int value) {
    m94 = value;
    return 1;
}

class Obj_5a1e0 {
  public:
    char Set(int value);
    char pad[0x58];
    int m58;
};

char Obj_5a1e0::Set(int value) {
    m58 = value;
    return 1;
}
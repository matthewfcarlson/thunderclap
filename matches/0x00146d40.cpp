class Obj_146d40 {
  public:
    char pad[0x28];
    int m28;
    char Set(int value);
};

char Obj_146d40::Set(int value) {
    m28 = value;
    return 1;
}

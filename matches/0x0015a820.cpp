class Obj {
  public:
    char Set(char value);
    char pad[12];
};

char Obj::Set(char value) {
    pad[12] = value;
    return 1;
}

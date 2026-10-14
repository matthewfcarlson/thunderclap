class Obj_1a2860 {
  public:
    char Set(char x);
    char pad[0xf8];
};

char Obj_1a2860::Set(char x) {
    pad[0xf8] = x;
    return 1;
}

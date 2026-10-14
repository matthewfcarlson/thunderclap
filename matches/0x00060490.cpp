class Obj_60490 {
  public:
    char pad[0x50];
    char m50;
    char Set(char c);
};

char Obj_60490::Set(char c) {
    m50 = c;
    return 1;
}

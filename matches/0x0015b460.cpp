class Obj_15b460 {
  public:
    char pad[0x48];
    char f48;
    char Set(char c);
};
char Obj_15b460::Set(char c) {
    f48 = c;
    return 1;
}

class Obj_14c540 {
  public:
    char pad[12];
    char value;
    char Set(unsigned char c);
};
char Obj_14c540::Set(unsigned char c) {
    value = (char)c;
    return 1;
}
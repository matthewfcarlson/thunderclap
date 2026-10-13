class Obj {
  public:
    char pad[12];
    char value;
    char Set(unsigned char c);
};
char Obj::Set(unsigned char c) {
    value = (char)c;
    return 1;
}
class Thing {
  public:
    char pad[20];
    char m14;
    char SetByte(char v);
};
char Thing::SetByte(char v) {
    m14 = v;
    return 1;
}

class Obj {
  public:
    void Set(char c);
    char pad[0x7c4];
    char value;
};
void Obj::Set(char c) {
    value = c;
}

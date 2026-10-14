class Obj {
  public:
    void SetX(char c);
    char pad[0xf4];
};
void Obj::SetX(char c) {
    pad[0xf4] = c;
}

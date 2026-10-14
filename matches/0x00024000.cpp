class Obj_24000 {
  public:
    void SetX(char c);
    char pad[0xf4];
};
void Obj_24000::SetX(char c) {
    pad[0xf4] = c;
}

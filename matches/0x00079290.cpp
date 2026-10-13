class Obj {
  public:
    char pad[0x3548];
    int value;
    void Clear();
};
void Obj::Clear() {
    value = 0;
}

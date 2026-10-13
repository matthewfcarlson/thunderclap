class Obj {
  public:
    char pad[0x14];
    int value;
    int GetValue();
};
int Obj::GetValue() {
    return value;
}
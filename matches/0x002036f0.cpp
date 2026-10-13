class Obj {
  public:
    char pad[0x5a0];
    int value;
    int Get();
};
int Obj::Get() {
    return value;
}
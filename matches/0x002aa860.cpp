class Obj {
  public:
    char pad[0x38];
    int value;
    int Get();
};
int Obj::Get() {
    return value;
}

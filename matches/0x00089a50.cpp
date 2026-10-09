class Obj {
    char pad[0xac4];

  public:
    int value;
    int Get();
};
int Obj::Get() {
    return value;
}
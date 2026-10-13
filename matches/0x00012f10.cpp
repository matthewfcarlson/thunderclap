class Obj {
  public:
    char pad[0x70];
    int m70;
    int* Get70();
};
int* Obj::Get70() {
    return &m70;
}

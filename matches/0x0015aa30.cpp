class Obj {
  public:
    char pad[0x60];
    int m;
    int* Get();
};
int* Obj::Get() {
    return &m;
}
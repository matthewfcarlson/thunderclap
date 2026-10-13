class Obj {
    char pad[0x20];
    int m;

  public:
    int* Get();
};
int* Obj::Get() {
    return &m;
}

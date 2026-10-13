class Obj {
  public:
    char pad[0xa8];
    int value;
    int* Get();
};
int* Obj::Get() {
    return &value;
}

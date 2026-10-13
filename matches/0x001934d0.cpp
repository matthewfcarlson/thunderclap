class Obj {
  public:
    char pad[0xbc];
    int* Get();
};
int* Obj::Get() {
    return (int*)((char*)this + 0xbc);
}

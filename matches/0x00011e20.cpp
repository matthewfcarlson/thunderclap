class Obj {
  public:
    char pad[16];
    int* Get();
};
int* Obj::Get() {
    return (int*)((char*)this + 0x10);
}

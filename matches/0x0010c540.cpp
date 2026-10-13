class Obj {
  public:
    char pad[0x18];
    int* Get();
};
int* Obj::Get() {
    return (int*)((char*)this + 0x18);
}
class Obj {
  public:
    char pad[0x10];
    int* Get();
};

int* Obj::Get() {
    return (int*)((char*)this + 0x10);
}
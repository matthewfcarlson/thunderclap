class Obj {
  public:
    char pad[0x20];
    int* Get();
};

int* Obj::Get() {
    return (int*)((char*)this + 0x20);
}
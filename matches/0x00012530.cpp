class Obj {
  public:
    char pad[0x2c];
    int* Get();
};

int* Obj::Get() {
    return (int*)((char*)this + 0x2c);
}

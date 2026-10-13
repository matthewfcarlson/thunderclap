class Obj {
  public:
    char pad[0x18];
    int* GetData();
};

int* Obj::GetData() {
    return (int*)((char*)this + 0x18);
}

class Obj {
    char pad[0x20];

  public:
    int Get();
};
int Obj::Get() {
    return *(int*)((char*)this + 0x20);
}

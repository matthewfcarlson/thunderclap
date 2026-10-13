class Obj {
  public:
    char pad[0x48];
    int* m;
    int* Get();
};
int* Obj::Get() {
    return (int*)((char*)this + 0x48);
}

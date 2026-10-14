class Obj_1a1fc0 {
  public:
    char pad[0x20];
    int* Get();
};
int* Obj_1a1fc0::Get() {
    return (int*)((char*)this + 0x20);
}
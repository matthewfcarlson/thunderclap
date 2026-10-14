class Obj_10c540 {
  public:
    char pad[0x18];
    int* Get();
};
int* Obj_10c540::Get() {
    return (int*)((char*)this + 0x18);
}
class Obj_48030 {
  public:
    char pad[0x10];
    int* Get();
};

int* Obj_48030::Get() {
    return (int*)((char*)this + 0x10);
}
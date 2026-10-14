class Obj_47ea0 {
  public:
    char pad[0x18];
    int* Get();
};

int* Obj_47ea0::Get() {
    return (int*)((char*)this + 0x18);
}

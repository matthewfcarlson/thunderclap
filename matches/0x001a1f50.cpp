class Obj_1a1f50 {
  public:
    char pad[0x10];
    int* Get();
};

int* Obj_1a1f50::Get() {
    return (int*)((char*)this + 0x10);
}

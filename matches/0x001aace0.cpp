class Obj_1aace0 {
  public:
    char pad[0x10];
    int* Get();
};

int* Obj_1aace0::Get() {
    return (int*)((char*)this + 0x10);
}

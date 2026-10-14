class Obj_12530 {
  public:
    char pad[0x2c];
    int* Get();
};

int* Obj_12530::Get() {
    return (int*)((char*)this + 0x2c);
}

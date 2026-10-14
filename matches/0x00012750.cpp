class Obj_12750 {
  public:
    char pad[0x20];
    int* Get();
};

int* Obj_12750::Get() {
    return (int*)((char*)this + 0x20);
}
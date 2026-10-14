class Obj_1934d0 {
  public:
    char pad[0xbc];
    int* Get();
};
int* Obj_1934d0::Get() {
    return (int*)((char*)this + 0xbc);
}

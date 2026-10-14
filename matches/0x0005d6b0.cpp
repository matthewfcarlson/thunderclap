class Obj_5d6b0 {
  public:
    char pad[0x18];
    int* GetData();
};

int* Obj_5d6b0::GetData() {
    return (int*)((char*)this + 0x18);
}

class Obj_12500 {
    char pad[0x20];

  public:
    int Get();
};
int Obj_12500::Get() {
    return *(int*)((char*)this + 0x20);
}

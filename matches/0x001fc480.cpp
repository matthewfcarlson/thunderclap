class Obj_1fc480 {
  public:
    char pad[0x20c];
    int Get();
};

int Obj_1fc480::Get() {
    return *(int*)((char*)this + 0x20c);
}

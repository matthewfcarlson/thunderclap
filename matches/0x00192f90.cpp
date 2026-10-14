class Obj_192f90 {
  public:
    char pad[16];
    int* Get();
};

int* Obj_192f90::Get() {
    return (int*)((char*)this + 16);
}

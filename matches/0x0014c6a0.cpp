class Obj_14c6a0 {
  public:
    char pad[0x10];
    int* Field();
};

int* Obj_14c6a0::Field() {
    return (int*)((char*)this + 0x10);
}

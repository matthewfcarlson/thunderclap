class Obj {
  public:
    char pad[0x10];
    int* Field();
};

int* Obj::Field() {
    return (int*)((char*)this + 0x10);
}

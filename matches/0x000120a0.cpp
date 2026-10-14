class Obj_120a0 {
  public:
    char pad[0x28];
    void* Get28();
};

void* Obj_120a0::Get28() {
    return (char*)this + 0x28;
}
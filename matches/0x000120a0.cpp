class Obj {
  public:
    char pad[0x28];
    void* Get28();
};

void* Obj::Get28() {
    return (char*)this + 0x28;
}
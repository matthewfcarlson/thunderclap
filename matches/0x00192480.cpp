class Obj {
  public:
    char pad[0x88];
    char* Get();
};

char* Obj::Get() {
    return (char*)((char*)this + 0x88);
}

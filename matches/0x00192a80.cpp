class Obj {
  public:
    char pad[0x84];
    char* Get();
};

char* Obj::Get() {
    return (char*)this + 0x84;
}

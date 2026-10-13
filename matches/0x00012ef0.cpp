class Obj {
  public:
    char pad[0x58];
    char* Get();
};

char* Obj::Get() {
    return (char*)this + 0x58;
}

class Obj {
  public:
    char pad[0x30];
    char* Get30();
};

char* Obj::Get30() {
    return (char*)this + 0x30;
}

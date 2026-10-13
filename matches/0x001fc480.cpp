class Obj {
  public:
    char pad[0x20c];
    int Get();
};

int Obj::Get() {
    return *(int*)((char*)this + 0x20c);
}

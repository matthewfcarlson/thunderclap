class Sub {
  public:
    void* Get();
};

class Obj {
  public:
    char pad[0x58];
    Sub sub;
    void* Get();
};

void* Obj::Get() {
    return (char*)this + 0x58;
}

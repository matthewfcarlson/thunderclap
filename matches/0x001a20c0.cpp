class Sub_1a20c0 {
  public:
    void* Get();
};

class Obj_1a20c0 {
  public:
    char pad[0x58];
    Sub_1a20c0 sub;
    void* Get();
};

void* Obj_1a20c0::Get() {
    return (char*)this + 0x58;
}

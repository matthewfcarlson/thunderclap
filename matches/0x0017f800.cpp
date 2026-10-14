struct Sub_17f800 {
    int* Get() { return (int*)((char*)this + 0x18); }
};

class Obj_17f800 {
  public:
    char pad[0x18];
    Sub_17f800* GetField();
};

Sub_17f800* Obj_17f800::GetField() {
    return (Sub_17f800*)((char*)this + 0x18);
}

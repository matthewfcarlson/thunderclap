struct Sub {
    int* Get() { return (int*)((char*)this + 0x18); }
};

class Obj {
  public:
    char pad[0x18];
    Sub* GetField();
};

Sub* Obj::GetField() {
    return (Sub*)((char*)this + 0x18);
}

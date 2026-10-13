class Obj {
  public:
    char pad[0x78];
    void* mField;
    void* GetField();
};

void* Obj::GetField() {
    return (char*)this + 0x78;
}

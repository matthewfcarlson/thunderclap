class Obj_15acd0 {
  public:
    char pad[0x78];
    void* mField;
    void* GetField();
};

void* Obj_15acd0::GetField() {
    return (char*)this + 0x78;
}

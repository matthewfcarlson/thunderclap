class Thing {
  public:
    char pad[0x70];
    void* field;
    void* GetField();
};

void* Thing::GetField() {
    return &field;
}

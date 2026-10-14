class Thing_192a30 {
  public:
    char pad[0x70];
    void* field;
    void* GetField();
};

void* Thing_192a30::GetField() {
    return &field;
}

class A {
  public:
    char pad[0x18];
    void* m18;
};
void* __fastcall FUN_001aad50(A* self) {
    return &self->m18;
}
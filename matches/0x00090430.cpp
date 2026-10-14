class C {
  public:
    char pad[0x10cc];
    void* m;
    void Set(void* v);
};
void C::Set(void* v) {
    m = v;
}

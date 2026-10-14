class C_90430 {
  public:
    char pad[0x10cc];
    void* m;
    void Set(void* v);
};
void C_90430::Set(void* v) {
    m = v;
}

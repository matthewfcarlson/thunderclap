class Obj {
  public:
    char pad[16];
    void* m;
    void* Get();
};
void* Obj::Get() {
    return &m;
}
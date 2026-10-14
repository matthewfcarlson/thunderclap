class Obj {
  public:
    char pad[0xc4];
    struct Sub* m;
    void Run();
};
struct Sub {
    char pad[0x1e0];
    void Fn();
};
void Obj::Run() {
    ((Sub*)((char*)m + 0x1e0))->Fn();
}

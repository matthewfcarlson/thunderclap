class Obj_99880 {
  public:
    char pad[0xc4];
    struct Sub_99880* m;
    void Run();
};
struct Sub_99880 {
    char pad[0x1e0];
    void Fn();
};
void Obj_99880::Run() {
    ((Sub_99880*)((char*)m + 0x1e0))->Fn();
}

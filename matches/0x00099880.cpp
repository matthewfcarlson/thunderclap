class Obj_99880 {
  public:
    char pad[0xc4];
    struct Sub_99880* m;
    void Run(int, int);
};
struct Sub_99880 {
    char pad[0x1e0];
    void Fn(int, int);
};
void Obj_99880::Run(int a0, int a1) {
    ((Sub_99880*)((char*)m + 0x1e0))->Fn(a0, a1);
}

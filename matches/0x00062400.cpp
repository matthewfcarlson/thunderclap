// Same code shape as 0x001703a0 (propagated; names are from that function)
extern int vtable;
class Part {
  public:
    int x[2];
    void Init();
};
class Obj {
  public:
    int vt;
    char pad[0x14];
    Part p18;
    Part p20;
    void Final();
    void Run();
};
void Obj::Run() {
    vt = (int)&vtable;
    p20.Init();
    p18.Init();
    Final();
}
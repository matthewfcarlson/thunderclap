class Obj_fdf20 {
  public:
    char pad0[0x40];
    int a;
    int b;
    int c;
};
class Target_fdf20 {
  public:
    char pad0[0x0c];
    Obj_fdf20* source;
    char pad1[0x50 - 0x10];
    int a;
    int b;
    int c;
    void Run();
};
void Target_fdf20::Run() {
    if (source) {
        a = source->a;
        b = source->b;
        c = source->c;
    }
}
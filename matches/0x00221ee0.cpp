class Inner_221ee0 {
  public:
    void Step();
    char pad[0x10];
};
class Obj_221ee0 {
  public:
    void Run();
    void Other();
    char pad0[0x40];
    Inner_221ee0 inner;
    int state;
};
void Obj_221ee0::Run() {
    switch (state) {
    case 0:
        inner.Step();
        state = 1;
        break;
    case 1:
        inner.Step();
        break;
    case 2:
        Other();
        break;
    }
}

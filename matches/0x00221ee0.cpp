class Inner {
public:
    void Step();
    char pad[0x10];
};
class Obj {
public:
    void Run();
    void Other();
    char pad0[0x40];
    Inner inner;
    int state;
};
void Obj::Run() {
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

struct Manager { int Make(); int Finish(int, int); };
struct Obj {
    char pad0[0x10];
    int field10;
    char pad14[0x30];
    Manager* field44;
    void Stage(int, int, int);
    void Other(int, int);
    void target(int, int);
};
struct Item { void Last(); };
void Obj::target(int a, int b) {
    if (!b) {
        int v = field44->Make();
        Stage(v, a, 0);
        field44->Finish(v, (int)&field10);
    } else {
        Other(a, b);
        ((Item*)b)->Last();
    }
}
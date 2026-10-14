struct Manager_29ffd0 {
    int Make();
    int Finish(int, int);
};
struct Obj_29ffd0 {
    char pad0[0x10];
    int field10;
    char pad14[0x30];
    Manager_29ffd0* field44;
    void Stage(int, int, int);
    void Other(int, int);
    void target(int, int);
};
struct Item_29ffd0 {
    void Last();
};
void Obj_29ffd0::target(int a, int b) {
    if (!b) {
        int v = field44->Make();
        Stage(v, a, 0);
        field44->Finish(v, (int)&field10);
    } else {
        Other(a, b);
        ((Item_29ffd0*)b)->Last();
    }
}
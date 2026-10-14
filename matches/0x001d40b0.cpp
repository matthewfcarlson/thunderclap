struct Obj_1d40b0 {
    char pad[8];
    int value;
    void Init();
    void Target();
};
void DoThing(int, int, int);
void Obj_1d40b0::Target() {
    Init();
    DoThing(value, 2, 0);
}
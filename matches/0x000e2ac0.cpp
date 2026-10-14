class Obj_e2ac0 {
  public:
    char pad[0xac];
    volatile int field;
    void Set(int);
};
void ReleaseThing(int);
void Obj_e2ac0::Set(int value) {
    int old = field;
    if (old != 0) {
        ReleaseThing(old);
        field = 0;
        field = value;
    } else {
        field = value;
    }
}
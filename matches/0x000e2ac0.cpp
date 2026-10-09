class Obj {
  public:
    char pad[0xac];
    volatile int field;
    void Set(int);
};
void ReleaseThing(int);
void Obj::Set(int value) {
    int old = field;
    if (old != 0) {
        ReleaseThing(old);
        field = 0;
        field = value;
    } else {
        field = value;
    }
}
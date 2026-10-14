struct Part_1f2e40 {
    char pad[8];
    void Reset();
};
struct Thing_1f2e40 {
    Part_1f2e40 a;
    Part_1f2e40 b;
    Part_1f2e40 c;
    Thing_1f2e40* Reset();
};
Thing_1f2e40* Thing_1f2e40::Reset() {
    a.Reset();
    b.Reset();
    c.Reset();
    return this;
}
struct Part {
    char pad[8];
    void Reset();
};
struct Thing {
    Part a;
    Part b;
    Part c;
    Thing* Reset();
};
Thing* Thing::Reset() {
    a.Reset();
    b.Reset();
    c.Reset();
    return this;
}
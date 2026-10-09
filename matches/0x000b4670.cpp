struct Sub {
    char pad[8];
    void Clear();
};
struct Thing {
    char pad[8];
    Sub a;
    Sub b;
    Sub c;
    void Clear();
};
void Thing::Clear() {
    c.Clear();
    b.Clear();
    a.Clear();
    ((Sub*)this)->Clear();
}
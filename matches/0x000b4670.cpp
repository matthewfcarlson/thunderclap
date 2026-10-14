struct Sub_b4670 {
    char pad[8];
    void Clear();
};
struct Thing_b4670 {
    char pad[8];
    Sub_b4670 a;
    Sub_b4670 b;
    Sub_b4670 c;
    void Clear();
};
void Thing_b4670::Clear() {
    c.Clear();
    b.Clear();
    a.Clear();
    ((Sub_b4670*)this)->Clear();
}
class X_79660 {
  public:
    void call(int);
};
class C_79660 {
  public:
    char pad[0x374c];
    X_79660* items[1];
    char pad2[0x379c - 0x3750];
    int count;
    void f(int);
};
void C_79660::f(int p) {
    for (int i = 0; i < count; ++i)
        items[i]->call(p);
}
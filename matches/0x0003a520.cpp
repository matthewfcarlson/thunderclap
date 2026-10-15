class Obj {
    char pad[0x328];
    void* p;
    char pad2[0x1b48 - 0x32c];
    char flag;

  public:
    void* Fn(int a, int b, int c, int d);
    char Do(int a, int b, int c, int d, void* p);
    void Fail();
};
void* Obj::Fn(int a, int b, int c, int d) {
    if (flag)
        return p;
    if (!Do(a, b, c, d, p)) {
        Fail();
        return 0;
    }
    return p;
}
struct Obj {
    char pad[0x90];
    int m;
    void Set(int v);
};
void Obj::Set(int v) {
    m = v;
}
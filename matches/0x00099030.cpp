struct O {
    char pad[0x90];
    int m;
    void Set(int v);
};
void O::Set(int v) {
    m = v;
}
class C_30a260 {
    char pad[0x18];
    int value;

  public:
    void set(int);
};
struct ThisCall_003099d0 {
    void called();
};
void C_30a260::set(int x) {
    value = x;
    ((ThisCall_003099d0*)(this))->called();
}
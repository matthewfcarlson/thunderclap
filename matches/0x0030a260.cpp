class C_30a260 {
    char pad[0x18];
    int value;

  public:
    void set(int);
};
void called();
void C_30a260::set(int x) {
    value = x;
    called();
}
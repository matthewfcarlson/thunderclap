class C {
    char pad[0x18];
    int value;

  public:
    void set(int);
};
void called();
void C::set(int x) {
    value = x;
    called();
}
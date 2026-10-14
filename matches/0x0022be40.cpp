class Target_22be40 {
    char pad[0x30];
    int a, b, c;

  public:
    void Set(const int* p);
};
void Target_22be40::Set(const int* p) {
    a = p[0];
    b = p[1];
    c = p[2];
}
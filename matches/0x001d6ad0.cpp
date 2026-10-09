class Target {
    char pad[0x17c];

  public:
    int a, b, c;
    void Set(int* p);
};
void Target::Set(int* p) {
    a = p[0];
    b = p[1];
    c = p[2];
}
class Target {
  public:
    char pad[0x37a4];
    int a;
    int b;
    void Set(int x, int y);
};

void Target::Set(int x, int y) {
    a = x;
    b = y;
}
class Target {
  public:
    char pad[0xc4];
    struct Sub* m;
    void Set(int a, int b);
};
struct Sub {
    char pad[0x258];
    int x;
    int y;
};
void Target::Set(int a, int b) {
    m->x = a;
    m->y = b;
}

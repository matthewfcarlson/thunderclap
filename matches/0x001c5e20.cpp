class Obj {
  public:
    void Fn(int a);
    char pad[16];
    struct Sub* m;
};

struct Sub {
    void Helper(int a);
};

void Obj::Fn(int a) {
    if (m)
        m->Helper(a);
}

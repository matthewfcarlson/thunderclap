struct Triple {
    int a;
    int b;
    int c;
};
class Owner {
  public:
    char pad[0x28];
    int m28;
    int m2c;
    int m30;
    bool Assign(Triple* p);
};
bool Owner::Assign(Triple* p) {
    m28 = p->a;
    m2c = p->b;
    m30 = p->c;
    return true;
}

class Inner {
  public:
    void Act(int, char);
};
class Obj {
  public:
    char pad[4];
    struct Mid {
        char pad[0x4c];
        Inner* p;
    }* mid;
    void Fn(void* p);
};
void Obj::Fn(void* p) {
    if (mid && mid->p)
        mid->p->Act(0x2e4, p == 0);
}
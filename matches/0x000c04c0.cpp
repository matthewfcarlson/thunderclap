class Obj {
  public:
    void action();
    char pad[4];
    Obj* other;
    int fn(void* p, int unused);
};
int Obj::fn(void* p, int unused) {
    if (!other)
        return -1;
    if (p)
        return -1;
    other->action();
    return 0;
}
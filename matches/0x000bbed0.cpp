class Other {
  public:
    void Fn();
};
class Obj {
  public:
    int dummy;
    Other* ptr;
    int target(void* a, void* b);
};
int Obj::target(void* a, void* b) {
    Other* p = ptr;
    if (!p)
        return -1;
    if (a)
        return -1;
    p->Fn();
    return 0;
}
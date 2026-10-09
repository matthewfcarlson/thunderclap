class Obj {
  public:
    void af8(int);
    void afaf();
};
class Thing {
  public:
    char pad[5];
    unsigned char flag;
    char pad2[2];
    Obj* ptr;
    void target(int);
};
void other();
void Thing::target(int arg) {
    if (flag) {
        if (ptr) {
            ptr->af8(arg);
            return;
        }
    } else {
        if (ptr)
            ptr->afaf();
        if (flag)
            other();
    }
}
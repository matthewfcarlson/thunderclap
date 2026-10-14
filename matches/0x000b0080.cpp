class Obj_b0080 {
  public:
    void af8(int);
    void afaf();
};
class Thing_b0080 {
  public:
    char pad[5];
    unsigned char flag;
    char pad2[2];
    Obj_b0080* ptr;
    void target(int);
};
void other();
void Thing_b0080::target(int arg) {
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
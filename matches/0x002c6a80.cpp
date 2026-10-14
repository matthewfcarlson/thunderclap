extern void* gVtable_2c6a80;
class DisplayTraversal {
  public:
    void* vptr;
    int a;
    unsigned char flag;
    unsigned char pad[3];
    int c;
    int d;
    int e;
    DisplayTraversal();
};
DisplayTraversal::DisplayTraversal() {
    a = 0;
    vptr = &gVtable_2c6a80;
    flag = 1;
    c = -1;
    d = 0;
    e = 0;
}
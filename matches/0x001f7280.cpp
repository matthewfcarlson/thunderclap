class Obj_1f7280 {
  public:
    void Act(int, int*);
};
Obj_1f7280* Get();
class Host_1f7280 {
  public:
    unsigned char target(int a, int b, int c, int d);
};
unsigned char Host_1f7280::target(int a, int b, int c, int d) {
    if (a < 0)
        return 0;
    Obj_1f7280* p = Get();
    if (p)
        p->Act(a, &b);
    return 1;
}
struct Helper {
    int F();
};
class Obj {
  public:
    char pad[4];
    Helper* m;
    int Fn(int a, int b);
};
int Obj::Fn(int a, int b) {
    if (m == 0)
        return -1;
    m->F();
    return 0;
}

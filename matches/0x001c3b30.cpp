class Helper_1c3b30 {
  public:
    int first(int);
    void second(int);
};
class Obj_1c3b30 {
  public:
    char pad[8];
    Helper_1c3b30* m;
    void target(int);
};
void Obj_1c3b30::target(int param) {
    int r = m->first(param);
    if (r)
        m->second(r);
}
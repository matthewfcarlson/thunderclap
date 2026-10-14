class Inner_99b90 {
  public:
    void Go(int a);
};
class Obj_99b90 {
  public:
    char pad[0xb8];
    Inner_99b90* m;
    void Fn(int a);
};
void Obj_99b90::Fn(int a) {
    if (m)
        m->Go(a);
}

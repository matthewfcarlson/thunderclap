class Helper {
  public:
    void Run(float f);
};
class Obj {
  public:
    char pad[0xb8];
    Helper* m;
    void Fn(float f);
};
void Obj::Fn(float f) {
    if (m)
        m->Run(f);
}

class Helper_99ae0 {
  public:
    void Run(float f);
};
class Obj_99ae0 {
  public:
    char pad[0xb8];
    Helper_99ae0* m;
    void Fn(float f);
};
void Obj_99ae0::Fn(float f) {
    if (m)
        m->Run(f);
}

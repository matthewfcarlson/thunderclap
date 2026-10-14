class Obj_fddb0 {
    char pad[0x34];
    int zero, a, b, c;

  public:
    void Set(int* p);
};
void Obj_fddb0::Set(int* p) {
    zero = 0;
    a = p[0];
    b = p[1];
    c = p[2];
}
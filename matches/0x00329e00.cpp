extern int gFlags_329e00;
extern int gCache_329e00[32];
class Obj_329e00 {
  public:
    char pad[0xc4];
    int values[32];
    void Helper(int, int, int);
    void Set(int, int, int, int);
};
void Obj_329e00::Set(int a, int b, int c, int d) {
    Helper(a, b, c);
    if (values[a] != d) {
        values[a] = d;
        gFlags_329e00 |= 0x800;
        gCache_329e00[a * 32] = d;
    }
}

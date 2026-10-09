void f133d0(int, int);
void f13600(int, int);
int f12f00(int, int);
float f130e0(int, int);
void f12d80(int, int);
class Obj {
  public:
    char pad[8];
    int field;
    bool target(int arg, float* out);
};
bool Obj::target(int arg, float* out) {
    f133d0(field, arg);
    f13600(field, -2);
    bool result = true;
    if (f12f00(field, -1) != 3)
        result = false;
    if (result)
        *out = f130e0(field, -1);
    f12d80(field, -2);
    return result;
}
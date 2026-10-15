extern "C" int __cdecl get();
extern "C" void __cdecl action(int, int, float);
class Obj {
    char pad[12];
    int value;

  public:
    void fn(unsigned int n);
};
void Obj::fn(unsigned int n) {
    if (get()) {
        int x = get();
        float f = (float)n;
        action(x, value, f);
    }
}
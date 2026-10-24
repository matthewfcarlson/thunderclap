extern int __cdecl f70ba0();
extern int __cdecl f6fd50(int, int);
extern int __cdecl f66eb0(int, int, int);
class Obj_277630 {
  public:
    char pad[0x14];
    int m14;
    int m18;
    int m1c;
    int m20;
    void run(int, int, int);
};
void Obj_277630::run(int a, int b, int c) {
    if (m1c == 0) {
        m20 = a;
        int x = f6fd50(f70ba0(), c);
        m18 = x;
        m14 = f66eb0(m20, x, b);
    }
    ++m1c;
}
extern int __cdecl f70ba0(int);
extern int __cdecl f6fd50(int);
extern int __cdecl f66eb0(int,int,int);
class Obj { public: char pad[0x14]; int m14; int m18; int m1c; int m20; void run(int,int,int); };
void Obj::run(int a, int b, int c) {
    if (m1c == 0) {
        m20 = a;
        int x = f70ba0(c);
        x = f6fd50(x);
        m18 = x;
        m14 = f66eb0(m20, x, b);
    }
    ++m1c;
}
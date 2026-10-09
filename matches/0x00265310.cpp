struct Temp { char x[0x18]; void f(int); void g(int,int); };
struct Obj { char pad[0x10]; int value; void run(int); };
void Obj::run(int param) {
    Temp t;
    t.f(value);
    t.g(param, 0);
}
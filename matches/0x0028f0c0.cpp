class ShaderCallback { public: virtual void f0(); virtual void f1(); virtual void f2(); virtual int vfunc_3(int); virtual void f4(); virtual void f5(); };
struct Matrix { unsigned long x[16]; };
class ShaderMatrixBroadcast : public ShaderCallback { public: int pad; int value; Matrix matrix; int vfunc_3(int param); };
class Receiver { public: virtual void a(); virtual void b(); virtual void c(); virtual void d(); virtual void e(); virtual void f(); virtual void g(); virtual void h(); virtual void i(); virtual void j(); virtual void send(int value, Matrix *matrix); };
int ShaderMatrixBroadcast::vfunc_3(int param) { Matrix copy; if (param) { int v = value; copy = matrix; Receiver *r = *(Receiver**)((char*)param + 0x10); r->send(v, &copy); } return param; }
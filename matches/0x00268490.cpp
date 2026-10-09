class Obj { public: virtual void f0(); virtual void f1(); virtual void f2(int); };
extern Obj* g_obj;
void target() { if (g_obj) g_obj->f2(1); g_obj = 0; }
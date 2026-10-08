class Inner { public: void f(); };
class Outer { public: Inner* p; void g(); };
void Outer::g() { p->f(); }
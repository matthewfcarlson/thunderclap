extern "C" void f1();
extern "C" void f2();
extern "C" unsigned char g;
void target() { f1(); f2(); g = 0; }

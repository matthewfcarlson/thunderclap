extern "C" void f1();
extern "C" void f2();
extern "C" unsigned char g_26dab0;
void target() {
    f1();
    f2();
    g_26dab0 = 0;
}

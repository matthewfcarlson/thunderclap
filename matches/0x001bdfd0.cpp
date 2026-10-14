extern "C" {
unsigned int g_x;
unsigned int g_y;
unsigned int g_z;
void __stdcall FUN_001bdfd0(unsigned int a, unsigned int b, unsigned int c) {
    g_x = a;
    g_y = b;
    g_z = c;
}
}

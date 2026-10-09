extern "C" unsigned char enabled;
struct Triple {
    int a, b, c;
};
struct Manager {
    void Run(Triple, Triple, Triple);
};
extern Manager* manager;
void __stdcall FUN_001eda90(int a, int b, int c, int d, int e, int f, int g, int h, int i) {
    if (enabled)
        manager->Run(*(Triple*)&a, *(Triple*)&d, *(Triple*)&g);
}
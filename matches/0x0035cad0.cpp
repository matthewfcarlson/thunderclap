extern "C" unsigned long long Hash(const char* s);
extern unsigned int g1_35cad0;
extern unsigned int g2_35cad0;
void FUN_0035cad0() {
    unsigned long long r = Hash("airsmash");
    g1_35cad0 = (unsigned int)r;
    g2_35cad0 = (unsigned int)(r >> 32);
}

extern "C" unsigned long long Hash(const char*);
unsigned int gHash_35c820[2];
void FUN_0035c820() {
    unsigned long long h = Hash("harrier");
    gHash_35c820[0] = (unsigned int)h;
    gHash_35c820[1] = (unsigned int)(h >> 32);
}

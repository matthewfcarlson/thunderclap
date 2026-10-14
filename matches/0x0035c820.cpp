extern "C" unsigned long long Hash(const char*);
unsigned int gHash[2];
void FUN_0035c820() {
    unsigned long long h = Hash("harrier");
    gHash[0] = (unsigned int)h;
    gHash[1] = (unsigned int)(h >> 32);
}

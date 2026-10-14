extern "C" unsigned long long __cdecl Hash(const char*) throw();
extern unsigned long gA;
extern unsigned long gB;
void FUN_0035c740() {
    unsigned long long h = Hash("hulk");
    gA = (unsigned long)h;
    gB = (unsigned long)(h >> 32);
}

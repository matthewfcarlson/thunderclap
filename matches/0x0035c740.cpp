extern "C" unsigned long long __cdecl Hash(const char*) throw();
extern unsigned long gA_35c740;
extern unsigned long gB_35c740;
void FUN_0035c740() {
    unsigned long long h = Hash("hulk");
    gA_35c740 = (unsigned long)h;
    gB_35c740 = (unsigned long)(h >> 32);
}

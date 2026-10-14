extern unsigned __int64 Find(const char*);
extern unsigned int gClass;
extern unsigned int gClassNext;
void FUN_0035ea90() {
    unsigned __int64 r = Find("mass_class");
    gClass = (unsigned int)r;
    gClassNext = (unsigned int)((r >> 32));
}

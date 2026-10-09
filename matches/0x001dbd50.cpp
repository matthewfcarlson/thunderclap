class Loader { public: void Config(const char*, int, int); void Type(const char*, int, int); void Pair(int, int); void Finish(int); };
extern Loader* __cdecl FUN_001d4c90();
extern const int vals[];
void __cdecl FUN_001dbd50() {
    Loader* p = FUN_001d4c90();
    if (p) {
        p->Config("constants", 1, 1);
        p->Type("weaponTypes", 0, 1);
        const int* q = vals;
        do {
            p->Pair(*q, *q);
            ++q;
        } while ((int)q < 0x4c6044);
        p->Finish(2);
    }
}
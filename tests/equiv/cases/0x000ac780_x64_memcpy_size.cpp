// eq64 mutant of matches/0x000ac780.cpp: a struct with a pointer copied by its 32-bit size
extern "C" void* __cdecl memcpy(void*, const void*, unsigned int);
struct Pair_ac780 {
    void* p;
    int v;
};
class Target_ac780 {
    char pad[0x14];

  public:
    Pair_ac780 a;
    Pair_ac780* b;
    void Set(int x);
};
void Target_ac780::Set(int x) {
    memcpy(&a, b, 8);
}

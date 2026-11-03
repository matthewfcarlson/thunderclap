// eq64 mutant of matches/0x000ac780.cpp: a field read at its 32-bit byte offset behind a pointer field
struct Inner_ac780 {
    void* p;
    int v;
};
class Target_ac780 {
    char pad[0x14];

  public:
    int value;
    Inner_ac780* in;
    void Set(int x);
};
void Target_ac780::Set(int x) {
    value = *(int*)((char*)in + 4) + x;
}

// eq64: 0x000ac780_x64_raw_offset with the field named (passes)
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
    value = in->v + x;
}

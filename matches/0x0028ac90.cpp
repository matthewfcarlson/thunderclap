class Obj_28ac90 {
  public:
    char pad[0x18];
    char* bits;
    void Normalize(unsigned int, unsigned int*, unsigned int*);
    void Query(unsigned int, bool*);
};
void Obj_28ac90::Query(unsigned int index, bool* out) {
    unsigned int local;
    Normalize(index, &index, &local);
    unsigned int offset = (index >> 5) * 4;
    unsigned int rem = index - offset * 8;
    unsigned int mask = 1;
    mask <<= rem;
    unsigned int value = *(unsigned int*)(bits + offset);
    *out = (value & mask) > 0;
}

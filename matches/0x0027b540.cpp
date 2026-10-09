// Same code shape as 0x0027b510 (propagated; names are from that function)
typedef unsigned char byte;
void thunk(void*);
class Partition {
  public:
    virtual Partition* vfunc_0(byte);
    char pad[0x0c];
    void* field10;
};
Partition* Partition::vfunc_0(byte param) {
    *(void**)this = (void*)0x42c1b4;
    if (field10)
        thunk(field10);
    if (param & 1)
        thunk(this);
    return this;
}
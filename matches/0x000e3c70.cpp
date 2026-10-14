extern "C" void* memcpy(void*, const void*, unsigned int);
class Obj_e3c70 {
  public:
    char pad[0x118];
    int block[10];
    char pad2[0x495c - 0x140];
    int vals[13];
    void Base(Obj_e3c70*);
    void Fn(Obj_e3c70*);
};
void Obj_e3c70::Fn(Obj_e3c70* p) {
    Base(p);
    memcpy((char*)this + 0x118, (char*)p + 0x118, 40);
    vals[0] = p->vals[0];
    vals[1] = p->vals[1];
    vals[2] = p->vals[2];
    vals[3] = p->vals[3];
    vals[5] = p->vals[5];
    vals[6] = p->vals[6];
    vals[7] = p->vals[7];
    vals[8] = p->vals[8];
    vals[9] = p->vals[9];
    vals[10] = p->vals[10];
    vals[11] = p->vals[11];
    vals[12] = p->vals[12];
}

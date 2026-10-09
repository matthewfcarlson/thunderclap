extern "C" void* memcpy(void*, const void*, unsigned int);
class Obj {
  public:
    char pad[4];
    char block[8][0x7c];
    unsigned int tail[2];
    void Copy(const Obj*);
};
void Obj::Copy(const Obj* s) {
    for (int i = 0; i < 8; i++)
        memcpy(block[i], s->block[i], 0x7c);
    tail[0] = s->tail[0];
    tail[1] = s->tail[1];
}
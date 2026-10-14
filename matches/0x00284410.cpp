class Worker_284410 {
  public:
    void Work(char*);
};
class Obj_284410 {
  public:
    char p0[12];
    unsigned count;
    Worker_284410* base;
    char* values;
    char p18[8];
    unsigned char flag;
    void Run(int);
};
void Obj_284410::Run(int arg) {
    if (flag) {
        unsigned i = 0;
        if (0 < count) {
            unsigned boff = 0;
            unsigned voff = 0;
            do {
                ((Worker_284410*)((char*)base + boff))->Work(values + voff);
                ++i;
                voff += 0x40;
                boff += 0x10;
            } while (i < count);
        }
        flag = 0;
    }
}

class Worker {
  public:
    void Work(char*);
};
class Obj {
  public:
    char p0[12];
    unsigned count;
    Worker* base;
    char* values;
    char p18[8];
    unsigned char flag;
    void Run(int);
};
void Obj::Run(int arg) {
    if (flag) {
        unsigned i = 0;
        if (0 < count) {
            unsigned boff = 0;
            unsigned voff = 0;
            do {
                ((Worker*)((char*)base + boff))->Work(values + voff);
                ++i;
                voff += 0x40;
                boff += 0x10;
            } while (i < count);
        }
        flag = 0;
    }
}

class Obj_d7f60 {
  public:
    char pad0[0x1d4];
    int result;
    char pad1[0x78];
    char slots[5][0x3c];
    char pad2[0x2c];
    char flag;
    void update();
};
void Obj_d7f60::update() {
    result = -1;
    int i = 0;
    char* p = &slots[0][0];
    do {
        if (!((flag == 0 && p[8] != 0) || *p == 0)) {
            result = i;
            return;
        }
        ++i;
        p += 0x3c;
    } while (i < 5);
}
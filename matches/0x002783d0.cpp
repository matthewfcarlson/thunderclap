class Obj_2783d0 {
    char pad[0xcc];

  public:
    char flag;
    char pad2[6];
    char x;
    char y;
    void f(int* a, int* b);
};
void Obj_2783d0::f(int* a, int* b) {
    if (flag == 0x55) {
        *a = -1;
        *b = -1;
    } else {
        *a = x - 0x31;
        *b = y - 0x41;
    }
}
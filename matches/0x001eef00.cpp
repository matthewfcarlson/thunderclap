class Helper_1eef00 {
  public:
    void init(int);
};
class Obj_1eef00 {
  public:
    char pad[12];
    char* data;
    void run();
};
void Obj_1eef00::run() {
    int i = 0;
    do {
        char* a = data + i;
        *(int*)(a + 8) = 0;
        *(int*)(a + 12) = 0;
        *(int*)(a + 16) = 0;
        a[20] = 0;
        *(float*)(a + 32) = 100.0f;
        *(int*)(a + 36) = 0;
        ((Helper_1eef00*)(a + 24))->init(0);
        i += 40;
    } while (i < 4000);
}

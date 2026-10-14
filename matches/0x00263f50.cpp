class Service_263f50 {
  public:
    int Get();
};
extern Service_263f50* g_263f50;
class Thing_263f50 {
  public:
    char p[8];
    int a;
    char b[4];
    int c[12];
    int d;
    int e;
    void Init();
};
void Thing_263f50::Init() {
    a = 0;
    b[0] = 0;
    b[1] = 0;
    b[2] = 0;
    b[3] = 0;
    c[0] = 0;
    c[1] = 0;
    c[2] = 0;
    c[3] = 0;
    c[4] = 0;
    c[5] = 0;
    c[6] = 0;
    c[7] = 0;
    c[8] = 0;
    c[9] = 0;
    c[10] = 0;
    c[11] = 0;
    unsigned int x = g_263f50->Get();
    e = 0;
    d = x / 1000;
}
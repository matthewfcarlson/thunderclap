extern "C" char DAT_0042e324[];
class ExpressionLoader {
  public:
    int a;
    int b;
    int c;
    int d;
    int e;
    ExpressionLoader();
};
ExpressionLoader::ExpressionLoader() {
    volatile int* p = &a;
    p[1] = 0;
    p[2] = 0x21000;
    p[3] = 0;
    p[4] = 0;
    p[0] = ((int)DAT_0042e324);
}
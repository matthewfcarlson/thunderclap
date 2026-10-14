class X_e7f10 {
  public:
    int fallback();
};
int __stdcall target(int a, int b, X_e7f10* c) {
    int r = 2;
    switch (a) {
    case 0x1517370d:
        r = 3;
        break;
    case 0x39761bad:
        r = 1;
        break;
    case 0x7e52767b:
        r = 2;
        break;
    default:
        c->fallback();
        break;
    }
    return r;
}
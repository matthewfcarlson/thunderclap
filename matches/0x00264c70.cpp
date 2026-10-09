class X {
  public:
    int f0;
    int f4;
    int f8;
    int fc;
    int f10;
    unsigned int f14;
    unsigned int f18;
    unsigned int f1c;
    unsigned int f20;

    int Fn();
};

int X::Fn() {
    unsigned int edx = f14;
    unsigned int eax = f18;
    int count;
    if (edx <= eax) {
        count = (int)(eax - edx) >> 3;
    } else {
        count = ((int)(eax - f1c) >> 3) + ((int)(f20 - edx) >> 3);
    }
    if ((unsigned int)count > 0u || f8 != 0)
        return 1;
    return 0;
}

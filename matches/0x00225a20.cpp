class Thing {
  public:
    char pad0[0x20];
    int value20;
    char pad[0x200];
    char b224;
    char b225;
    char pad226[2];
    int d228;
    int d22c;
    int d230;
    char b234;
    char b235;
    char pad236[2];
    int d238;
    int d23c;
    void First(Thing*);
    void Second(int);
    Thing* Copy(Thing*);
};
Thing* Thing::Copy(Thing* src) {
    First(src);
    Second(src->value20);
    b224 = src->b224;
    b225 = src->b225;
    d228 = src->d228;
    d22c = src->d22c;
    d230 = src->d230;
    b234 = src->b234;
    b235 = src->b235;
    d238 = src->d238;
    d23c = src->d23c;
    return this;
}
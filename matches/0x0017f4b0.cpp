class Obj {
  public:
    char m1;
    char m2;
    char m3;
    char m4;
    char m5;
    char m6;
    char m7;
    char m8;
    char m9;
    char m10;
    char pad[4];
    int mValue;
    char Set(int v);
};
char Obj::Set(int v) {
    mValue = v;
    return 1;
}

class Obj {
    char pad[0x28];
    int value;

  public:
    char Set(int n);
};
char Obj::Set(int n) {
    value = n;
    if (n > 6)
        n = 6;
    value = n;
    if (n <= 2)
        n = 2;
    value = n;
    return 1;
}
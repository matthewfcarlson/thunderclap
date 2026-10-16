class Obj {
    char pad[12];
    int value;

  public:
    char Set(int x);
};
char Obj::Set(int x) {
    value = x;
    return 1;
}
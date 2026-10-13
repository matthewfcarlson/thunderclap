class Obj {
  public:
    char pad[0x44];
    int m44;
    char Set(int v);
};
char Obj::Set(int v) {
    m44 = v;
    return 1;
}

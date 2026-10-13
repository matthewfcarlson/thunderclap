struct Sub {
    int value;
};
class Obj {
  public:
    char pad[0x1c];
    Sub s;
    char Set(int x);
};

char Obj::Set(int x) {
    s.value = x;
    return 1;
}

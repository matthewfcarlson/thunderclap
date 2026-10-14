struct Sub_115300 {
    int value;
};
class Obj_115300 {
  public:
    char pad[0x1c];
    Sub_115300 s;
    char Set(int x);
};

char Obj_115300::Set(int x) {
    s.value = x;
    return 1;
}

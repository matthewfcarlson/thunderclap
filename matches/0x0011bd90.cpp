class Obj_11bd90 {
  public:
    char pad[0x1c];
    int m1c;
    char SetVal(int x);
};

char Obj_11bd90::SetVal(int x) {
    m1c = x;
    return 1;
}

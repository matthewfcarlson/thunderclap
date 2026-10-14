class Obj_68b10 {
  public:
    char pad[12];
    int value;
    char Set(int v);
};

char Obj_68b10::Set(int v) {
    value = v;
    return 1;
}

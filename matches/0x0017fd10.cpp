class Obj_17fd10 {
  public:
    char Set(int);
    char pad[0x28];
    int m;
};

char Obj_17fd10::Set(int v) {
    m = v;
    return 1;
}

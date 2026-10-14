class Obj_681c0 {
  public:
    char pad[0x28];
    int value;
    char Set(int v);
};
char Obj_681c0::Set(int v) {
    value = v;
    return 1;
}
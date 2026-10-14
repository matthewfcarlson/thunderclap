class Obj_b07c0 {
    char pad[0x494];
    int value;

  public:
    unsigned char Set(int x);
};
unsigned char Obj_b07c0::Set(int x) {
    value = x;
    return 1;
}
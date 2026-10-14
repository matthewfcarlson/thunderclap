class Obj_192330 {
  public:
    char Set(int v);
    char pad[0x60];
    int m;
};
char Obj_192330::Set(int v) {
    m = v;
    return 1;
}
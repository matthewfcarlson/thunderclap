class Obj_68500 {
  public:
    char pad[0x10];
    int m10;
    char SetDamage_00068500(int x);
};

char Obj_68500::SetDamage_00068500(int x) {
    m10 = x;
    return 1;
}

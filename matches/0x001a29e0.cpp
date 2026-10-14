struct Sub {
    char m128;
};

class Obj {
  public:
    char pad[0x128];
    Sub m;
    char Fn(char c);
};

char Obj::Fn(char c) {
    m.m128 = c;
    return 1;
}

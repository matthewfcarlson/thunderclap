struct Sub_1a29e0 {
    char m128;
};

class Obj_1a29e0 {
  public:
    char pad[0x128];
    Sub_1a29e0 m;
    char Fn(char c);
};

char Obj_1a29e0::Fn(char c) {
    m.m128 = c;
    return 1;
}

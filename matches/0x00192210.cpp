class Obj_192210 {
  public:
    char pad[0x2c];
    int m2c;
    bool Set(int value);
};

bool Obj_192210::Set(int value) {
    m2c = value;
    return true;
}

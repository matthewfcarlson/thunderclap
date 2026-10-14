class Obj_18f100 {
  public:
    char pad[0x6c];
    int value;
    bool Set(int x);
};

bool Obj_18f100::Set(int x) {
    value = x;
    return true;
}

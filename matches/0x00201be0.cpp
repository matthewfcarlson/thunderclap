void FUN_00267830(void*, int, int);

class X {
  public:
    void Fn(int value);
};

void X::Fn(int value) {
    FUN_00267830((char*)this + 0x28, value, 0x40);
}

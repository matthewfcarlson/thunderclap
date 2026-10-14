class Obj_602b0 {
  public:
    char pad[0x60];
    int a;
    int b;
    int c;
    bool Set(const void* src);
};

bool Obj_602b0::Set(const void* src) {
    a = *(const int*)src;
    b = *(const int*)((const char*)src + 4);
    c = *(const int*)((const char*)src + 8);
    return true;
}

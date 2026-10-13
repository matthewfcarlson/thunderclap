class Obj {
  public:
    char Fn(int arg);
};

char Obj::Fn(int arg) {
    char old = *(char*)((char*)this + 0x4e);
    *(char*)((char*)this + 0x4e) = 0;
    (void)arg;
    return old;
}

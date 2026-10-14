class Obj_1f7110 {
  public:
    char Fn(int arg);
};

char Obj_1f7110::Fn(int arg) {
    char old = *(char*)((char*)this + 0x4e);
    *(char*)((char*)this + 0x4e) = 0;
    (void)arg;
    return old;
}

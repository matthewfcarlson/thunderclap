class Thing {
  public:
    int FUN_00036f00(int);
    unsigned char FUN_00036fd0(int);
};
unsigned char Thing::FUN_00036fd0(int arg) {
    int index = FUN_00036f00(arg);
    if (index < 0)
        return 0;
    return *((unsigned char*)this + ((index + 0x226) << 4));
}

// cl-flags: /Oy- /O1
class DName {
    char data[8];

  public:
    DName(int);
};
class Thing_34ceaa {
  public:
    int mValue;
    char pad[0x28];
    DName a;
    DName b;
    Thing_34ceaa();
};
Thing_34ceaa::Thing_34ceaa() : a(3), b(1) {
    *(int*)this |= -1;
}

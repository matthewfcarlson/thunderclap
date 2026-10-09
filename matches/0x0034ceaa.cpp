// cl-flags: /Oy- /O1
class DName {
    char data[8];

  public:
    DName(int);
};
class Thing {
  public:
    int mValue;
    char pad[0x28];
    DName a;
    DName b;
    Thing();
};
Thing::Thing() : a(3), b(1) {
    *(int*)this |= -1;
}

// cl-flags: /O1
class Obj {
  public:
    char pad[0x3c];
    char m3c;
    char Set(char c);
};

char Obj::Set(char c) {
    m3c = c;
    return 1;
}

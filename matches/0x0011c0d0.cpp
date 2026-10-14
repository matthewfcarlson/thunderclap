// cl-flags: /O1
class Obj_11c0d0 {
  public:
    char pad[0x3c];
    char m3c;
    char Set(char c);
};

char Obj_11c0d0::Set(char c) {
    m3c = c;
    return 1;
}

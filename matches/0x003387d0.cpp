class Obj_3387d0 {
  public:
    char pad[0x836];
    char s[1];
    unsigned char target(char c);
};
unsigned char Obj_3387d0::target(char c) {
    char* p = s;
    while (*p != 0) {
        if (*p == c)
            return 1;
        ++p;
    }
    return 0;
}
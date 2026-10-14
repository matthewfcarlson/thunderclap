class Obj_3387a0 {
  public:
    char pad[0x832];
    char str[1];
    bool contains(char c);
};
bool Obj_3387a0::contains(char c) {
    char* p = str;
    while (*p) {
        if (*p == c)
            return true;
        ++p;
    }
    return false;
}
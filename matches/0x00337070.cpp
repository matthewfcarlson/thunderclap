class Obj {
  public:
    char m4;
    void Copy(char* s);
};
void Obj::Copy(char* s) {
    char* dst = (char*)this + 4;
    char* p = s;
    char c;
    do {
        c = *p;
        *(dst + (p - s)) = c;
        ++p;
    } while (c);
}

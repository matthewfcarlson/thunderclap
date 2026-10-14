extern "C" int sprintf(char*, const char*, ...);
int Cmp(const char*, const char*, int);
struct Dev_b0740 {
    char p[0x14];
    char name[0x40];
    int type;
    void Set(const char* s);
};
void Dev_b0740::Set(const char* s) {
    sprintf(name, "%s", s);
    if (name[0] == 0) {
        type = 3;
        return;
    }
    if (Cmp(name, "Keyboard", 8) == 0) {
        type = 1;
        return;
    }
    type = (Cmp(name, "Mouse", 5) != 0) ? 0 : 2;
}

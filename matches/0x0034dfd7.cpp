// cl-flags: /Oy- /O1
class DName {
  public:
    DName(const char* s);
    DName(const DName& o);
    DName(int status);
    char pad[8];
};
extern const char* gName;
DName __cdecl getDim(int n);
class UnDecorator {
  public:
    static DName __cdecl getStringEncoding(char* s, int h);
};
DName __cdecl UnDecorator::getStringEncoding(char* s, int h) {
    DName result(s);
    if (*gName++ == '@' && *gName++ == '_') {
        gName++;
        getDim(0);
        getDim(0);
        while (*gName && *gName != '@')
            gName++;
        if (*gName == 0) {
            gName--;
            return DName(2);
        }
        gName++;
        return DName(result);
    }
    return DName(1);
}
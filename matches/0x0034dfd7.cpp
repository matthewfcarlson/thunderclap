// cl-flags: /Oy- /O1
class DName {
  public:
    DName(const char* s);
    DName(const DName& o);
    DName(int status);
    char pad[8];
};
extern const char* gName_34dfd7;
DName __cdecl getDim(int n);
class UnDecorator {
  public:
    static DName __cdecl getStringEncoding(char* s, int h);
};
DName __cdecl UnDecorator::getStringEncoding(char* s, int h) {
    DName result(s);
    if (*gName_34dfd7++ == '@' && *gName_34dfd7++ == '_') {
        gName_34dfd7++;
        getDim(0);
        getDim(0);
        while (*gName_34dfd7 && *gName_34dfd7 != '@')
            gName_34dfd7++;
        if (*gName_34dfd7 == 0) {
            gName_34dfd7--;
            return DName(2);
        }
        gName_34dfd7++;
        return DName(result);
    }
    return DName(1);
}
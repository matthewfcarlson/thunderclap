extern "C" int strcmp(const char*, const char*);
extern char* gSentinel;
extern char gEmpty[];
class StringLike {
  public:
    char* mData;
    char Compare(const char* other);
};
char StringLike::Compare(const char* other) {
    char* p = mData;
    if (other == 0)
        return p == gSentinel;
    if (p == gSentinel)
        p = gEmpty;
    return strcmp(p, other) == 0;
}

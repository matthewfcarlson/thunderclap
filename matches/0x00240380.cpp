extern "C" int strcmp(const char*, const char*);
extern char* gSentinel_240380;
extern char gEmpty_240380[];
class StringLike {
  public:
    char* mData;
    char Compare(const char* other);
};
char StringLike::Compare(const char* other) {
    char* p = mData;
    if (other == 0)
        return p == gSentinel_240380;
    if (p == gSentinel_240380)
        p = gEmpty_240380;
    return strcmp(p, other) == 0;
}

extern "C" char* strcpy(char*, const char*);
extern "C" unsigned int strlen(const char*);
class Alloc {
  public:
    char* Allocate(unsigned int, int);
};
extern Alloc gAlloc;
class Obj {
    char pad[12];
    char* text;

  public:
    void Set(const char* s);
};
void Obj::Set(const char* s) {
    text = gAlloc.Allocate(strlen(s) + 1, 4);
    strcpy(text, s);
}
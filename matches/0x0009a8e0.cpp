extern "C" char DAT_00404c20[];
extern char s1_9a8e0[];
extern char s2_9a8e0[];
extern char s3_9a8e0[];
extern char s4_9a8e0[];
extern char __cdecl Convert(const char*);
class Method3_9a8e0 {
  public:
    void Init(void*, int);
    Method3_9a8e0(void*, int);
    char a[0x10];
    char b10;
    char b11;
    char b12;
    char pad13[5];
    char b18;
    char pad19[3];
    int field1c;
};
Method3_9a8e0::Method3_9a8e0(void* p, int value) {
    Init(p, 3);
    *(int*)this = ((int)DAT_00404c20);
    field1c = value;
    b18 = Convert(s1_9a8e0);
    b10 = Convert(s2_9a8e0);
    b11 = Convert(s3_9a8e0);
    b12 = Convert(s4_9a8e0);
}
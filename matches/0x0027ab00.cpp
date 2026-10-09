extern const char fmt[];
extern int Format(char *, const char *, float *, float *, float *);
class Obj { public: char pad[0x10]; int index; char rest[1]; bool Check(int); bool Run(int a, float *p); };
bool Obj::Run(int a, float *p) {
    if (Check(a)) return Format((char *)((char *)this + 0xd38 + index * 0x60), fmt, p, (float *)((char *)p + 4), (float *)((char *)p + 8)) == 3;
    return false;
}
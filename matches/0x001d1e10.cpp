void __cdecl f1(void*, int);
void __cdecl f2(void*, int);
void __cdecl f3(void*, int);

struct Obj_1d1e10 {
    char pad[8];
    void* member;
    bool Do(int a, unsigned char b);
};

bool Obj_1d1e10::Do(int a, unsigned char b) {
    f1(member, a);
    f2(member, b);
    f3(member, -3);
    return true;
}

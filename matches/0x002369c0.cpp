void F1(void* a, const char* s);
void F2(void* a, const char* s);
void F3(void* a, const char* s);
void F4(void* a, const char* s);
void F5(void* a, const char* s);
void F6(void* a, const char* s);
void F7(void* a, const char* s);
void F8(void* a, const char* s);
void F9(void* a, const char* s);
void Target(void* p) {
    F1(p, "breakPoint");
    F2(p, "comment");
    F3(p, "execute");
    F4(p, "opportunity");
    F5(p, "print");
    F6(p, "sequence");
    F7(p, "spawn");
    F8(p, "stop");
    F9(p, "wait");
}

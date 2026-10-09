void Cleanup(void*, void*);
void Release(void*);
struct Obj { void* a; void* b; void Target(); };
void Obj::Target() {
    Cleanup(a, b);
    if (a) Release(a);
    a = 0;
    b = 0;
}
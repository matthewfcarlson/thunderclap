extern float GetThing(void*, void*);
extern int CheckThing(void*, void*);
extern int GetName(void*, int);
extern int GetType(void*, void*);
extern int GetNameByType(void*, int);
extern int Format(void*, const char*, int, int);
extern void Report(void*, void*, int);
extern const float Zero;
float Target(void* a, void* b) {
    float f = GetThing(a, b);
    if (f == Zero) {
        if (CheckThing(a, b) == 0) {
            int x = GetName(a, 3);
            int y = GetType(a, b);
            y = GetNameByType(a, y);
            int z = Format(a, "%s expected, got %s", x, y);
            Report(a, b, z);
        }
    }
    return f;
}
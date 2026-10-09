extern int gFlags;
extern int gCache[32];
class Obj { public: char pad[0xc4]; int values[32]; void Helper(int, int, int); void Set(int, int, int, int); };
void Obj::Set(int a, int b, int c, int d) {
    Helper(a, b, c);
    if (values[a] != d) {
        values[a] = d;
        gFlags |= 0x800;
        gCache[a * 32] = d;
    }
}

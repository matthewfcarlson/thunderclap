class Obj { public: char pad[5]; signed char count; char gap[0x28]; unsigned short values[1]; void f(unsigned short); };
void Obj::f(unsigned short value) {
    values[(int)count] = value;
    ++count;
}
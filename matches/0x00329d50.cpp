extern int gFlags;
extern int gValues[];
class Obj {
public:
    char pad[0x94];
    int slots[1];
    void helper(int, int, int);
    void update(int index, int a, int b, int value);
};
void Obj::update(int index, int a, int b, int value)
{
    helper(index, a, b);
    if (slots[index] != value) {
        slots[index] = value;
        gFlags |= 0x800;
        gValues[index * 32] = value;
    }
}
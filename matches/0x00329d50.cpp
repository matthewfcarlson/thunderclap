extern int gFlags_329d50;
extern int gValues_329d50[];
class Obj_329d50 {
  public:
    char pad[0x94];
    int slots[1];
    void helper(int, int, int);
    void update(int index, int a, int b, int value);
};
void Obj_329d50::update(int index, int a, int b, int value) {
    helper(index, a, b);
    if (slots[index] != value) {
        slots[index] = value;
        gFlags_329d50 |= 0x800;
        gValues_329d50[index * 32] = value;
    }
}
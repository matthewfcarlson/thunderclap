struct Vec {
    char pad[0x1c];
    int* begin;
    int* end;
};
class Obj {
    char pad[0x98];
    Vec* v;
    char pad2[0x10];
    void** items;

  public:
    void* Get(int index);
};
void* Obj::Get(int index) {
    if (index < 0)
        return 0;
    int** p = &v->begin;
    if (index < (p[1] - p[0]))
        return items[index];
    return 0;
}
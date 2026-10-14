class Finder_65c50 {
  public:
    int Find(int, int);
};
class Manager_65c50 {
  public:
    char pad[0x20];
    Finder_65c50* finder;
};
extern Manager_65c50* gManager_65c50;
class Owner_65c50 {
  public:
    char pad0[0x170];
    struct Entry {
        int a;
        int b;
    } entries[40];
    int count;
};
int __fastcall Target(Owner_65c50* self) {
    int i = 0;
    int result = 0;
    if (self->count > 0) {
        Owner_65c50::Entry* e = self->entries;
        do {
            Finder_65c50* f = gManager_65c50->finder;
            result = f->Find(e->a, e->b);
            if (*(char*)((char*)result + 0x1b84) != 0)
                return result;
            ++i;
            ++e;
        } while (i < self->count);
    }
    return 0;
}

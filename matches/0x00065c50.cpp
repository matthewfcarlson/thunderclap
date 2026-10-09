class Finder {
  public:
    int Find(int, int);
};
class Manager {
  public:
    char pad[0x20];
    Finder* finder;
};
extern Manager* gManager;
class Owner {
  public:
    char pad0[0x170];
    struct Entry {
        int a;
        int b;
    } entries[40];
    int count;
};
int __fastcall Target(Owner* self) {
    int i = 0;
    int result = 0;
    if (self->count > 0) {
        Owner::Entry* e = self->entries;
        do {
            Finder* f = gManager->finder;
            result = f->Find(e->a, e->b);
            if (*(char*)((char*)result + 0x1b84) != 0)
                return result;
            ++i;
            ++e;
        } while (i < self->count);
    }
    return 0;
}

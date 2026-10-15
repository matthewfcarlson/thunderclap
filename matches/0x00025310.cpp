struct Info {
    char a[0x1b0];
    int key;
};
struct Item {
    char a[0x11c];
    Info* info;
    void Act(int);
};
struct Finder {
    Item* Find(int);
};
struct Root {
    char pad[0x44];
    Finder* finder;
    Item* Get(const int* id) {
        Finder* f = finder;
        return f->Find(*id);
    }
};
class Host {
  public:
    Root* root;
    char pad[8];
    int count;
    int entries[1];
    Item* Get(int i) {
        Root* r = root;
        return r->Get(&entries[i]);
    }
    void Run(int key, volatile int arg);
};
void Host::Run(int key, volatile int arg) {
    for (int i = 0; i < count; i++) {
        Item* p = Get(i);
        if (p && p->info && p->info->key == key)
            p->Act(arg);
    }
}
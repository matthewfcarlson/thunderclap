// cl-flags: /O2

class List;

class ColorHolder {
  public:
    void Set(float* c);
};

struct Item {
    char pad0[8];
    ColorHolder ch;
    char pad1[0x60 - 8 - 1];
    Item() throw();
};

class List {
  public:
    void Add(Item* it);
};

class This {
  public:
    List* GetList();
    This* Build();
};

void* operator new(unsigned int) throw();

extern float* gColors[3];

void __cdecl FUN_00238b60(int a, int b);
void __cdecl FUN_00238330(int a, int b);

This* This::Build() {
    List* list = GetList();
    Item* a = new Item();
    a->ch.Set(gColors[0]);
    list->Add(a);
    Item* b = new Item();
    b->ch.Set(gColors[1]);
    list->Add(b);
    Item* c = new Item();
    c->ch.Set(gColors[2]);
    list->Add(c);
    FUN_00238b60(0x10b2a0, 0);
    FUN_00238330(0x10b2b0, 0);
    return this;
}

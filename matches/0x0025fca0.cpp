extern "C" int strcmp(const char*, const char*);
class Text {
  public:
    const char* Get();
};
class Item {
  public:
    char pad[0x58];
    Text text;
};
int Compare(Text* a, Item* b) {
    return strcmp(a->Get(), b->text.Get());
}
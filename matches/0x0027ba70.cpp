class Item {
  public:
    virtual void release(int);
    int x;
    int a, b, c;
    int tail;
};
class List {
  public:
    Item* begin;
    Item* end;
    void erase(Item*, Item*);
};
void List::erase(Item* first, Item* last) {
    Item* e = end;
    if (last != e) {
        int delta = (char*)last - (char*)first;
        do {
            first->a = *(int*)((char*)first + delta + 8);
            first->b = *(int*)((char*)first + delta + 12);
            first->c = last->c;
            ++first;
            ++last;
        } while (last != e);
    }
    Item* old = end;
    for (Item* p = first; p != old; ++p)
        p->release(0);
    end = first;
}
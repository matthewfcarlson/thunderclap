class Item_27ba70 {
  public:
    virtual void release(int);
    int x;
    int a, b, c;
    int tail;
};
class List_27ba70 {
  public:
    Item_27ba70* begin;
    Item_27ba70* end;
    void erase(Item_27ba70*, Item_27ba70*);
};
void List_27ba70::erase(Item_27ba70* first, Item_27ba70* last) {
    Item_27ba70* e = end;
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
    Item_27ba70* old = end;
    for (Item_27ba70* p = first; p != old; ++p)
        p->release(0);
    end = first;
}
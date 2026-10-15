class Node {
  public:
    char pad[8];
    void Update(int);
};
class Container {
  public:
    Node* Find(int);
    void Remove(int);
    void Erase(void*, Node*);
};
class Owner {
  public:
    char pad[8];
    Container items;
    void Act(int, int);
};
void Owner::Act(int key, int value) {
    Container* c = &items;
    Node* n = c->Find(key);
    if (n) {
        c->Remove(key);
        n->Update(value);
        c->Erase((char*)n + 8, n);
    }
}
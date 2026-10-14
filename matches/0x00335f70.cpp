struct Node {
    int first;
    int dummy;
    int kind;
    Node* child;
};
struct Manager {
    char pad[0x44];
    int count;
    Node* Get(int);
};
extern int Size(int);
class Obj {
  public:
    char pad[4];
    Manager* mgr;
    int** data;
    int Fetch(int index, int n);
};
int Obj::Fetch(int index, int n) {
    if (index < 0)
        return 0;
    if (index >= mgr->count)
        return 0;
    if (mgr->Get(index)->kind != 9)
        return 0;
    int* p = (int*)((char*)data[index] + 4);
    if (mgr->Get(index)->child->first != 10)
        return 0;
    p = (int*)((char*)p + Size(10) * n);
    return *p;
}
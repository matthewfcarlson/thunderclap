struct Part {
    char pad[8];
    char a;
    char b;
    void Copy(const Part*);
};
class CCharacter_3ec70 {
    char pad[0x22b8];
    Part part;

  public:
    void Set(const Part* p);
};
void CCharacter_3ec70::Set(const Part* p) {
    Part* q = &part;
    q->Copy(p);
    q->a = p->a;
    q->b = p->b;
}
class OpportunityAction_236ee0 {
  public:
    virtual void f0();
    virtual void f1(void*);
    OpportunityAction_236ee0* next;
};
class Owner_236ee0 {
  public:
    OpportunityAction_236ee0* head;
    void run(void*);
};
void Owner_236ee0::run(void* arg) {
    for (OpportunityAction_236ee0* p = head; p != 0; p = p->next)
        p->f1(arg);
}
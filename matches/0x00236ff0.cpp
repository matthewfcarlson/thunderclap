#include "gen/fight.h"
struct OpportunityAction_nv_236ff0 {
    void Link(fight::OpportunityAction*);
};
class List {
  public:
    fight::OpportunityAction* head;
    int Add(fight::OpportunityAction* n);
};
int List::Add(fight::OpportunityAction* n) {
    if (!n)
        return -1;
    fight::OpportunityAction* last = 0;
    fight::OpportunityAction* p = head;
    int count = 0;
    while (p) {
        last = p;
        p = (*(fight::OpportunityAction * *)&p->f_04);
        ++count;
    }
    ((OpportunityAction_nv_236ff0*)(n))->Link(p);
    if (last)
        ((OpportunityAction_nv_236ff0*)(last))->Link(n);
    else
        head = n;
    return count;
}
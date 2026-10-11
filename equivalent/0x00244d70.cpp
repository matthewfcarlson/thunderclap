// STATUS: equivalent (tools/equiv.py level 3: 65 inputs, branch coverage 6/6)
// om::EntityType::vfunc_0 @ 0x00244d70
struct ListNode {
    ListNode *self;
    ListNode *link1;
    ListNode *link2;
    int count;
};

struct ListHead {
    ListNode *first;
    ListNode node;
};

extern ListHead *DAT_004cc084;
extern ListHead *DAT_004cc088;
extern int DAT_004e5f10;

namespace om {
class EntityType {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();

    char pad0[0x30 - 4];
    char blockA[0x38];
    char blockB[1];
};
}

void FUN_00244230(ListHead *head, om::EntityType *type, void *block);
void FUN_00244430(ListHead *head, om::EntityType *type, void *block);

void om::EntityType::vfunc_0()
{
    ListHead *a = DAT_004cc084;
    ListHead *b = DAT_004cc088;

    if (DAT_004e5f10 == 0) {
        if (a) {
            ListNode *n = &a->node;
            n->self = n;
            a->node.link1 = n;
            a->node.link2 = n;
            a->node.count = 0;
            a->first = n;
        }
        if (b) {
            ListNode *n = &b->node;
            n->self = n;
            b->node.link1 = n;
            b->node.link2 = n;
            b->node.count = 0;
            b->first = n;
        }
    }

    FUN_00244230(a, this, blockA);
    FUN_00244430(b, this, blockB);
    DAT_004e5f10++;
}

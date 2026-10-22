// STATUS: equivalent (tools/equiv.py level 3: 2862 inputs, branch coverage 48/50, incomplete)
// FUN_002fdf40 @ 0x002fdf40
class CollisionObject_2fdf40;

struct Name_2fdf40 {
    int lo;
    int hi;
    void FUN_0027af60(int lo, int hi);
    void FUN_0027b040(const char *s);
};

class Node;

struct NodeList_2fdf40 {
    Node **begin;
    Node **end;
    Node **cap;
};

class Node {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual int vfunc_6();
    char pad04[4];
    int id;
    char pad0c[8];
    NodeList_2fdf40 *children;
    void FUN_00306930(Node *child);
    Node *FUN_00306c60();
    void FUN_00306600(int arg);
};

class CollisionAABB_2fdf40 : public Node {
public:
    CollisionAABB_2fdf40 *FUN_00312900();
};

class CollisionObject_2fdf40 {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6(int a, int b);
    char pad04[4];
    Name_2fdf40 name;
    CollisionObject_2fdf40 *FUN_00304f50(Node *source);
};

class Made_2fdf40 {
public:
    char pad0[8];
    Name_2fdf40 name;
    Made_2fdf40 *FUN_002f6220(void *a, void *b, void *c, int d);
};

struct Registry_2fdf40 {
    char pad0[0x20];
    struct Lookup_2fdf40 *lookup;
};

struct Lookup_2fdf40 {
    Node *FUN_00306190(int id, char flag);
};

struct Part_2fdf40 {
    char pad0[0x30];
    int f30;
    char pad34[4];
    float f38;
    char pad3c[0x64 - 0x3c];
    char f64[0x28];
    char f8c[1];
};

struct Table_2fdf40 {
    char pad0[0x18];
    void *f18;
    char pad1c[0x1fc - 0x1c];
    Part_2fdf40 **parts;
};

void *__cdecl FUN_0008d690(unsigned int size);
void *__cdecl FUN_00263ea0(unsigned int size);
void *__cdecl FUN_002efa90(CollisionObject_2fdf40 *shape, Made_2fdf40 *made, int zero);

class Builder {
public:
    char pad0[0x70];
    Table_2fdf40 *table;
    Registry_2fdf40 *registry;
    void *FUN_002fdf40(int id, int nameLo, int nameHi);
};

void *Builder::FUN_002fdf40(int id, int nameLo, int nameHi)
{
    Node *node = 0;
    int matchCount = 0;
    Made_2fdf40 *made = 0;
    CollisionObject_2fdf40 *shape = 0;

    if (registry != 0) {
        node = registry->lookup->FUN_00306190(id, 0);
        if (node != 0) {
            NodeList_2fdf40 *list = node->children;
            if (list != 0 && (((char *)list->end - (char *)list->begin) & ~3) != 0) {
                Node *first = 0;
                int mismatch = 0;
                Node **p = list->begin;
                for (unsigned i = 0; i < (unsigned)(list->end - list->begin); i++, p++) {
                    Node *c = *p;
                    if (c->id == id) {
                        if (first == 0)
                            first = c;
                    } else {
                        mismatch++;
                    }
                }
                if (mismatch > 0) {
                    matchCount = (int)(list->end - list->begin) - mismatch;
                    if (matchCount > 1) {
                        void *mem = FUN_0008d690(0x44);
                        CollisionAABB_2fdf40 *merged = 0;
                        if (mem != 0)
                            merged = ((CollisionAABB_2fdf40 *)mem)->FUN_00312900();
                        for (unsigned i = 0; i < (unsigned)(node->children->end - node->children->begin); i++) {
                            Node *c = node->children->begin[i];
                            if (c->id == id)
                                merged->FUN_00306930(c);
                        }
                        node = merged;
                    } else {
                        node = first;
                    }
                }
            }
            Node *copy = node->FUN_00306c60();
            copy->FUN_00306600(0);
            if (matchCount > 1) {
                if (node->children != 0)
                    node->children->end = node->children->begin;
                node->vfunc_1();
            }
            void *mem = FUN_00263ea0(0x80);
            shape = 0;
            if (mem != 0)
                shape = ((CollisionObject_2fdf40 *)mem)->FUN_00304f50(copy);
            shape->vfunc_6(0, 1);
            if ((nameLo | nameHi) != 0)
                shape->name.FUN_0027af60(nameLo, nameHi);
            else
                shape->name.FUN_0027b040("JointObjectDefaultName");
        }
    }

    if (table != 0) {
        Part_2fdf40 *part = table->parts[id];
        if (part != 0 && part->f38 > 0.0f) {
            void *mem = FUN_00263ea0(0x1f8);
            if (mem != 0)
                made = ((Made_2fdf40 *)mem)->FUN_002f6220(table->f18, part->f8c, part->f64, part->f30);
            else
                made = 0;
            if ((nameLo | nameHi) != 0)
                made->name.FUN_0027af60(nameLo, nameHi);
            else
                made->name.FUN_0027b040("JointObjectDefaultName");
        }
    }

    if (shape == 0 && made == 0)
        return 0;
    return FUN_002efa90(shape, made, 0);
}

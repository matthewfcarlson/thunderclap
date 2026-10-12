// STATUS: equivalent (tools/equiv.py level 3: 87 inputs, branch coverage 31/32, incomplete)
// FUN_002801b0 @ 0x002801b0
class Node {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual int v5();
    virtual void v6(float ms, int flags);
    virtual bool v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual int v15();
    virtual void v16(int a);
    virtual void v17();
    virtual void v18(int a);
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27(int a);
};

struct Entry {
    unsigned char active;  // 0x00
    char pad01[7];
    Node *part;            // 0x08
};

struct Mixer {
    char pad00[0x3c];
    Entry *begin;          // 0x3c
    Entry *end;            // 0x40
};

class Part : public Node {
public:
    char pad04[0x48 - 4];
    char **items;          // 0x48 (16-byte records, first word is a Node*)
    char **itemsEnd;       // 0x4c
    char pad50[0xa4 - 0x50];
    Node *sink;            // 0xa4
};

class Voice : public Node {
public:
    char pad04[0x44 - 4];
    Mixer *mixer;          // 0x44
    Node *fx0;             // 0x48 (unused here)
    Node *fx1;             // 0x4c
    Node *fx2;             // 0x50
};

struct Slot {
    unsigned char retired; // 0x00
    char pad01[0x44 - 1];
    Voice *voice;          // 0x44
    Node *aux;             // 0x48
    char pad4c[0x58 - 0x4c];
    float timer;           // 0x58
    char pad5c[4];
};

class VoicePool {
public:
    char pad00[0x1c];
    Slot slots[100];       // 0x1c
    void FUN_002801b0(float dt);
};

static void StopFx(Node *&fx)
{
    fx->v16(2);
    fx->v18(1);   // the original reloads the member after the first call
}

void VoicePool::FUN_002801b0(float dt)
{
    for (int i = 0; i < 100; i++) {
        Slot *s = &slots[i];
        Voice *v = s->voice;
        if (v == 0)
            continue;
        v->v6(dt * 1000.0f, 0);
        if (v->v7()) {
            if (s->voice) {
                s->voice->v1();
                s->voice = 0;
            }
            if (s->aux) {
                s->aux->v1();
                s->aux = 0;
            }
            continue;
        }
        if (!(s->timer >= 0.0f))
            continue;
        s->timer = s->timer - dt;
        if (!(s->timer < 0.0f))
            continue;
        if (s->retired) {
            if (s->voice) {
                s->voice->v1();
                s->voice = 0;
            }
            if (s->aux) {
                s->aux->v1();
                s->aux = 0;
            }
            continue;
        }
        if (s->voice->v5() == 4) {
            Voice *cur = s->voice;
            Mixer *m = cur->mixer;
            unsigned char n = (unsigned char)(m->end - m->begin);
            for (int k = 0; k < (int)n; k++) {
                Part *p = (Part *)m->begin[(unsigned char)k].part;
                if (p->v15() == 4) {
                    int count = ((char *)p->itemsEnd - (char *)p->items) >> 4;
                    for (int j = 0; j < count; j++) {
                        Node *item = *(Node **)((char *)p->items + j * 16);
                        item->v27(0);
                    }
                    StopFx(p->sink);
                } else {
                    m->begin[(unsigned char)k].active = 0;
                }
            }
            if (cur->fx1)
                StopFx(cur->fx1);
            if (cur->fx2)
                StopFx(cur->fx2);
        }
        s->retired = 1;
        s->timer = 4.0f;
    }
}

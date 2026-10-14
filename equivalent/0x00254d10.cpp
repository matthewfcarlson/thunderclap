// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 12/12)
// audio::SeqCommandLogicRepeat::vfunc_0 @ 0x00254d10
struct Link_254d10 {
    Link_254d10* next;
};

class Command_254d10 {
public:
    virtual void v0();
    virtual void v1();
    virtual void Update(void* context);
    Link_254d10 link;             // 0x04
};

struct CommandList_254d10 {
    char pad00[0xc];
    Link_254d10* first;           // 0x0c
};

namespace audio { class SeqCommandLogicRepeat; }

struct Context {
    void FUN_0025dbd0(audio::SeqCommandLogicRepeat* self);
};

namespace audio {

class SeqCommandLogicRepeat {
public:
    virtual void vfunc_0(Context* context);
    virtual void vfunc_1();
    char pad04[4];
    CommandList_254d10* list;     // 0x08
    unsigned int count;    // 0x0c
    unsigned int limit;    // 0x10
    Command_254d10* current;      // 0x14
};

}

void audio::SeqCommandLogicRepeat::vfunc_0(Context* context)
{
    if (current == 0) {
        context->FUN_0025dbd0(this);
        return;
    }
    current->Update(context);
    Link_254d10* next = current->link.next;
    current = next ? reinterpret_cast<Command_254d10*>(reinterpret_cast<char*>(next) - 4) : 0;
    if (current == 0) {
        unsigned int n = limit;
        if (n != 0xffffffff)
            count++;
        if (count < n) {
            Link_254d10* head = list->first;
            current = head ? reinterpret_cast<Command_254d10*>(reinterpret_cast<char*>(head) - 4) : 0;
        }
    }
}

// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 2/2)
// FUN_0026d990 @ 0x0026d990
struct Obj_26d990;
struct Node {
    int value;
    int unused;
    Obj_26d990* owner;
    Node* next;
    Node* previous;
};
struct Obj_26d990 {
    char reserved[8];
    Node node;
    void* fiber;
    int field20;
    int field24;
    int field28;
    Node* current;
    Node* first;
    Node* last;
    unsigned char enabled;
    char pad39[7];
    int state;
    int threadId;
    int threadHandle;
};
extern "C" int FUN_0020c14b();
namespace XAPILIB {
    void* __stdcall ConvertThreadToFiber(void*);
    int __stdcall SetThreadPriority(int, int);
}
extern "C" void FUN_0026d8f0(Obj_26d990*);
extern "C" int DAT_004cd9d8;
void __cdecl FUN_0026d990(Obj_26d990* self) {
    self->first = 0;
    self->last = 0;
    self->enabled = 1;
    int thread = FUN_0020c14b();
    self->threadId = thread;
    self->threadHandle = -2;
    self->field28 = 0;
    self->node.value = 0;
    self->node.unused = 0;
    self->fiber = XAPILIB::ConvertThreadToFiber(0);
    self->node.owner = self;
    self->field20 = 0;
    self->field24 = 0;
    self->current = &self->node;
    if (!self->first) {
        self->first = &self->node;
        self->node.previous = 0;
    } else {
        self->last->next = &self->node;
        self->node.previous = self->last;
    }
    self->last = &self->node;
    self->node.next = 0;
    FUN_0026d8f0(self);
    self->state = 2;
    XAPILIB::SetThreadPriority(self->threadHandle, DAT_004cd9d8);
}
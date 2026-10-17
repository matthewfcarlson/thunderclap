// STATUS: equivalent (tools/equiv.py level 3: 2993 inputs, branch coverage 4/4)
// FUN_001efca0 @ 0x001efca0
struct CSoundCommand_PlayCuedNISEvent {
    static void* operator new(unsigned int, void* place) { return place; }
    virtual void method();
    int next;
    int previous;
    int eventId;
};
struct SoundQueue {
    void FUN_001ef260(CSoundCommand_PlayCuedNISEvent* command);
};
extern SoundQueue* DAT_004e3710;
void* __cdecl FUN_0008d710(int size, int category);
void __stdcall FUN_001efca0(int eventId) {
    SoundQueue* queue = DAT_004e3710;
    if (queue) {
        void* memory = FUN_0008d710(16, 6);
        CSoundCommand_PlayCuedNISEvent* command = 0;
        if (memory) {
            command = new (memory) CSoundCommand_PlayCuedNISEvent;
            command->eventId = eventId;
            command->next = 0;
            command->previous = 0;
        }
        queue->FUN_001ef260(command);
    }
}
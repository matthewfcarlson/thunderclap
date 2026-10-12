// STATUS: equivalent (tools/equiv.py level 3: 179 inputs, branch coverage 52/54, incomplete)
// FUN_0026eab0 @ 0x0026eab0
struct Node {
    char reserved[0x10];
    Node* next;
    void FUN_0026de40();
};
struct Packet {
    char data[0x108];
    unsigned size;
    Packet* next;
};
struct PacketQueue {
    virtual void slot0();
    virtual void finish();
    virtual void slot2();
    virtual void slot3();
    virtual void consume(Packet*);
};
struct EventTarget {
    void FUN_0026e8f0(unsigned);
    void FUN_0026e920(unsigned, bool, bool, bool);
    void FUN_0026e970(unsigned, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned);
};
struct Event {
    unsigned type;
    EventTarget* target;
    unsigned value;
    union {
        unsigned word;
        unsigned char flags[4];
    } options;
    unsigned arg2;
    unsigned arg3;
    unsigned char arg4;
    char reserved19[3];
    unsigned char components[4];
    char remaining[0xe8];
};
struct Cursor {
    unsigned zero;
    void* handle;
    unsigned rest[31];
};
bool FUN_0026eed0();
int __cdecl FUN_0026ef10(void*);
void __cdecl FUN_0026eef0(void*);
int __cdecl FUN_0026ef50(Cursor*);
int __cdecl FUN_0026ef20(void*, void*);
int __cdecl FUN_0026ef30(void*, void*, unsigned, unsigned);
int __cdecl FUN_0026ef40(void*, void*, unsigned, unsigned);
struct Connection {
    char reserved[0x10];
    char input[0x58];
    char output[0x58];
    unsigned state;
    PacketQueue* queue;
    Packet* pending;
    Event event;
    Node* nodes;
    void FUN_0026e030();
    void FUN_0026e0e0();
    void FUN_0026e140(void*, unsigned);
    bool FUN_0026e200(EventTarget*);
    void FUN_0026eab0();
};
void Connection::FUN_0026eab0() {
    if (state == 0) {
        FUN_0026e030();
    } else if (state == 1) {
        if (FUN_0026eed0()) {
            if (FUN_0026ef10(input) < 0) {
                FUN_0026eef0(input);
                FUN_0026eef0(output);
                state = 0;
                return;
            }
            state = 2;
        }
    } else if (state == 2) {
        Cursor cursor = {0};
        cursor.handle = input;
        if (FUN_0026ef50(&cursor) > 0) {
            if (FUN_0026ef20(input, output) < 0) {
                state = 0;
            } else {
                FUN_0026eef0(input);
                Node* node = nodes;
                state = 3;
                for (; node; node = node->next) {
                    struct Notification { unsigned type; Node* node; } notification;
                    notification.type = 0;
                    notification.node = node;
                    FUN_0026e140(&notification, 8);
                }
                if (pending) {
                    for (;;) {
                        Packet* packet = pending;
                        if (FUN_0026ef40(output, packet, packet->size, 0) < 0) {
                            FUN_0026e0e0();
                            FUN_0026e030();
                            queue->finish();
                            break;
                        }
                        packet = pending;
                        pending = packet->next;
                        queue->consume(packet);
                        if (!pending) {
                            queue->finish();
                            break;
                        }
                    }
                }
            }
        }
    } else if (state == 3) {
        Cursor cursor = {0};
        cursor.handle = output;
        if (FUN_0026ef50(&cursor) > 0) {
            do {
                if (FUN_0026ef30(output, &event, 0x108, 0) < 0) {
                    FUN_0026e0e0();
                    FUN_0026e030();
                    break;
                }
                EventTarget* target = event.target;
                switch (event.type) {
                case 9:
                    if (FUN_0026e200(target))
                        target->FUN_0026e8f0(event.value);
                    break;
                case 10:
                    if (FUN_0026e200(target))
                        target->FUN_0026e920(event.value, event.options.flags[0] != 0,
                            event.options.flags[1] != 0, event.options.flags[2] != 0);
                    break;
                case 11:
                    if (FUN_0026e200(target))
                        target->FUN_0026e970(event.value, event.options.word, event.arg2,
                            event.arg3, event.arg4, event.components[0], event.components[1],
                            event.components[2], event.components[3]);
                    break;
                }
            } while (FUN_0026ef50(&cursor) > 0);
        }
    }
    for (Node* node = nodes; node; node = node->next)
        node->FUN_0026de40();
}

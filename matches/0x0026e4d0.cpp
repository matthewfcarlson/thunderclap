struct Message {
    int kind;
    int first;
    int second;
};
struct Handler {
    void FUN_0026e140(Message* message, int size);
    void FUN_0026e4d0(int first, int second);
};
void Handler::FUN_0026e4d0(int first, int second) {
    Message message;
    message.kind = 2;
    message.first = first;
    message.second = second;
    FUN_0026e140(&message, 12);
}
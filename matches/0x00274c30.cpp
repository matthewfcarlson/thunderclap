void init();
class Request { public: int v; int a; int b; };
class CompletionCallbackRequest : public Request { public: CompletionCallbackRequest(int arg); };
CompletionCallbackRequest::CompletionCallbackRequest(int arg) {
    v = 0x42b914;
    a = 0;
    init();
    v = 0x42b9dc;
    b = arg;
    init();
}
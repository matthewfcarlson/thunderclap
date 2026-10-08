extern char TrackFactoryTemplate_vftable_obj;

class TokenTrack;

class TrackFactoryTemplate {
public:
    void* mVptr;
    void Dtor_Base1();
    void Dtor_Base2();
    void* DeletingDtor(unsigned char flags);
};

void DeallocateObject(void* p);

void* TrackFactoryTemplate::DeletingDtor(unsigned char flags) {
    mVptr = &TrackFactoryTemplate_vftable_obj;
    Dtor_Base1();
    Dtor_Base2();
    if (flags & 1) {
        DeallocateObject(this);
    }
    return this;
}

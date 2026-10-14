// STATUS: equivalent (tools/equiv.py level 3: 44 inputs, branch coverage 16/16)
// FUN_00312ed0 @ 0x00312ed0
struct Groups {
    short* parents;
    int FUN_00312ed0(int count, short* output);
};
int Groups::FUN_00312ed0(int count, short* output) {
    unsigned int bytes = (unsigned int)count * 2;
    unsigned char* dest = (unsigned char*)output;
    for (unsigned int b=0; b<bytes; ++b) dest[b]=255;
    int groups=0;
    for(int i=0;i<count;++i) {
        short* p=parents;
        int root=i;
        int next=p[i];
        while(next!=root) { root=next; next=p[root]; }
        p[i]=(short)root;
        int representative=parents[i];
        if(representative!=i) {
            int label=output[representative];
            if(label==-1) { label=groups++; output[representative]=(short)label; }
            output[i]=(short)label;
        }
    }
    bytes=(unsigned int)groups*2;
    dest=(unsigned char*)parents;
    for(unsigned int b=0;b<bytes;++b) dest[b]=255;
    for(int i=0;i<count;++i) {
        int label=output[i];
        short previous=parents[label];
        output[i]=previous;
        parents[label]=(short)i;
    }
    return groups;
}
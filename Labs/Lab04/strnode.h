#ifndef STRNODE_H_
#define STRNODE_H_
#endif

struct strnode {
    char*                str;
    int                  length;
    struct strnode*      next;
};

struct strnode *strnode_create(char *s, int length);

#ifndef STRNODE_H_
#define STRNODE_H_
#endif

struct strnode {
    char                 str;
    int                  length;
    struct strnode*      next;
};

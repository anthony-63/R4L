#ifndef R4L_H
#define R4L_H

int *open_rbc (const char *rbcpath);
char *make_rbc (const char *srcpath);
char *exec_rbc (int *rbc);

#endif

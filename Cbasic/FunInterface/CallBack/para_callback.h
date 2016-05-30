/* para_callback.h */

#ifndef PARA_CALLBACK_H
#define PARA_CALLBACK_H

typedef void (*callback_t)(void *);
extern void repeat_three_time(callback_t,void *);

#endif

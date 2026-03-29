#ifndef RUN_H
#define RUN_H

#include "mem.h"
#include "command.h"

// Определение макроса для программного счетчика (PC)
// reg[7] — это обычно регистр R7 (PC) в PDP-11
#define pc reg[7]

// Прототип функции run
void run(void);

#endif // RUN_H
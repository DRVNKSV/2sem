#ifndef COMMAND_H
#define COMMAND_H

#include "mem.h"  // для типов byte, word, address

// Структура команды
typedef struct {
    word mask;          // маска для выделения кода операции
    word opcode;        // код операции
    char *name;         // имя команды
    void (*do_command)(void);  // указатель на функцию-обработчик
} Command;

// Прототипы функций-обработчиков команд
void do_halt(void);
void do_move(void);
void do_add(void);
void do_inc(void);
void do_sob(void);
void do_nothing(void);

// Внешние переменные
extern Command cmd[];

#endif // COMMAND_H
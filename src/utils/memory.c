/*
** EPITECH PROJECT, 2022
** tetris
** File description:
** No file there , just an epitech header example
*/

#include "utils.h"
#include "my.h"

static memory_t *get_node(void *new)
{
    static memory_t *head = NULL;

    if (new)
        return head = new;
    return head;
}

static void del_memory(void)
{
    memory_t *head = get_node(NULL);
    void *prev_to_free;
    void *head_void = head;

    while (head) {
        if (head->address)
            free((head->address));
        head = head->next;
    }
    head = head_void;
    while (head) {
        prev_to_free = head;
        head = head->next;
        free(prev_to_free);
    }
}

void *get_memory(size_t size)
{
    void *tmp_var = malloc(size);
    memory_t *head = get_node(NULL);
    memory_t *tmp = malloc(sizeof(memory_t));
    tmp->next = head;
    tmp->address = tmp_var;

    get_node(tmp);
    return tmp_var;
}

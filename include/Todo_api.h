#ifndef _TODO_API_FILE_
#define _TODO_API_FILE_

#include<stdbool.h>
#include<time.h>

/**
 * @brief Struct representing a todo item.
 */
typedef struct
{
    int id; /**< Unique identifier for the todo item. */
    char *msg; /**< Message describing the todo item. */
    bool is_done; /**< Flag indicating whether the todo item is done or not. */
    bool is_important; /**< Flag indicating whether the todo item is important or not. */
    time_t deadline; /**< Deadline for the todo item. */
    time_t date_created; /**< Date when the todo item was created. */
} todo_t;

typedef enum{
    status_OK,
    status_NOK,
} status_t;



// Api
todo_t todos_create(char* msg, bool is_important, time_t deadline);
status_t todos_delete(int id, todo_t * ret_to);
status_t todos_get_all(todo_t **ret_to, int *len);
status_t todos_get_important(todo_t *ret_to);
status_t todos_set_important(int id);


#endif // _TODO_API_FILE_

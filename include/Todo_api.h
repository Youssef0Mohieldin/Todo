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


/**
 * @brief to handel errors
 * 
 */
typedef enum{
    status_OK,
    status_NOK,
} status_t;


/**
 * @brief the main pointer to the todos
 * 
 */
static **todos = NULL;



// Api

/**
 * @brief returns a todo
 * @note must call delete to free the dynamic memory alocated
 * 
 * @param msg 
 * @param is_important 
 * @param deadline 
 * @return todo_t or NULL
 */
todo_t todos_create(char* msg, bool is_important, time_t deadline);


/**
 * @brief deletes the todo (frees the alocated memory)
 * 
 * @param id 
 * @param ret_to return location
 * @return status_t 
 */
status_t todos_delete(int id, todo_t * ret_to);

/**
 * @brief returns the full array of todos
 * 
 * @param ret_to return location (array pointer)
 * @param len 
 * @return status_t 
 */
status_t todos_get_all(todo_t **ret_to, int *len);

/**
 * @brief get the todos marked with the important flag
 * 
 * @param ret_to 
 * @return status_t 
 */
status_t todos_get_important(todo_t *ret_to);

/**
 * @brief mark a todo as important
 * 
 * @param id 
 * @return status_t 
 */
status_t todos_set_important(int id);


#endif // _TODO_API_FILE_

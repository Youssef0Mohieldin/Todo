#ifndef _TODO_API_FILE_
#define _TODO_API_FILE_

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include "utils.h"

/**
 * @brief Struct representing a todo item.
 */
typedef struct todo_st
{
    int id;              /**< Unique identifier for the todo item. */
    char *msg;           /**< Message describing the todo item. */
    bool is_done;        /**< Flag indicating whether the todo item is done or not. */
    bool is_important;   /**< Flag indicating whether the todo item is important or not. */
    time_t deadline;     /**< Deadline for the todo item. */
    time_t date_created; /**< Date when the todo item was created. */
    struct todo_st *next;
} todo_t;

/**
 * @brief to handel errors
 *
 */
typedef enum
{
    status_OK,
    status_NOK,
} status_t;


// Api

/**
 * @brief returns a pointer to last added task.
 * @note must call delete to free the dynamic memory alocated.
 * @note msg must be dynamicly alocated beforehand.
 *
 * @param msg
 * @param is_important
 * @param deadline
 * @param tasks -> address of tasks list
 * @return todo_t or NULL if could not create
 */

status_t todos_create(todo_t **todo, char *msg, bool is_important, time_t deadline);
/**
 * @brief deletes the todo (frees the alocated memory)
 *
 * @param id
 * @param ret_to return location
 * @return status_t
 */
status_t todos_delete(todo_t *todos, int id);

/**
 * @brief returns the full array of todos
 * @note can be used to check if the todos array is initialized
 *
 * @param ret_to return a the array of (pointers to todos) :(
 * @param len_ret number of items
 * @return status_t
 */
status_t todos_get_all(todo_t *todos, int *len_ret);


/**
 * @brief returns the full array of todos
 * @note can be used to check if the todos array is initialized
 *
 * @param ret_to return a the array of (pointers to todos) :(
 * @param len_ret number of items
 * @return status_t
 */
status_t todos_get_by_id(todo_t *todo, int id, todo_t *ret_to);

/**
 * @brief get the todos marked with the important flag
 *
 * @param ret_to
 * @return status_t
 */
status_t todos_get_important(todo_t *todos);

/**
 * @brief mark a todo as important
 *
 * @param id
 * @return status_t
 */
status_t todos_set_important(todo_t *todos,int id);

#endif // _TODO_API_FILE_

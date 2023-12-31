#ifndef _TODO_API_FILE_
#define _TODO_API_FILE_

#include<stdlib.h>
#include<stdbool.h>
#include<time.h>
#include<utils.h>

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
static todo_t **todos = NULL;
static int todos_len = 0;


// Api

/**
 * @brief returns a todo.
 * @note must call delete to free the dynamic memory alocated.
 * @note msg must be dynamicly alocated beforehand.
 * 
 * @param msg 
 * @param is_important 
 * @param deadline 
 * @return todo_t or NULL if could not create
 */
todo_t *todos_create(char* msg, bool is_important, time_t deadline);


/**
 * @brief deletes the todo (frees the alocated memory)
 * 
 * @param id 
 * @param ret_to return location
 * @return status_t 
 */
status_t todos_delete(int id);

/**
 * @brief returns the full array of todos
 * @note can be used to check if the todos array is initialized
 *  
 * @param ret_to return a the array of (pointers to todos) :(
 * @param len_ret number of items
 * @return status_t 
 */
status_t todos_get_all(todo_t ***ret_to, int *len_ret);

/**
 * @brief get the todos marked with the important flag
 * 
 * @param ret_to 
 * @return status_t 
 */
status_t todos_get_important(todo_t ***ret_to);

/**
 * @brief mark a todo as important
 * 
 * @param id 
 * @return status_t 
 */
status_t todos_set_important(int id);

/**
 * @brief returns number of todos
 * 
 * @return int 
 */
int todos_get_num();


#endif // _TODO_API_FILE_

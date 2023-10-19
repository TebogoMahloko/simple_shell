#include "shell.h"

/**
 * _myhistory - displays the history list, one command by line, preceded
 *              with line numbers, starting at 0.
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return:  0
 */
int _myhistory(info_t *info)
{
	print_list(info->history);
	return (0);
}

/**
 *  Move the variable declaration to the beginning of the function
 *  Return:  ret
 */
int unset_alias(info_t *info, char *str)
{
    char *p;
    int ret;
    char c;  

    p = _strchr(str, '=');
    if (!p)
        return 1;

    c = *p;  
    *p = 0;

    ret = delete_node_at_index(&(info->alias), get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
    
    *p = c;
    return ret;
}




/**
 * set_alias - Set an alias in info.
 * @info: Pointer to info_t structure.
 * @str: The alias to set.
 *
 * Return: 1 if setting alias fails, 0 otherwise.
 */
int set_alias(info_t *info, char *str)
{
    char *p;

    p = _strchr(str, '=');
    if (!p)
        return 1;
    
    if (!*++p)
        return unset_alias(info, str);

    unset_alias(info, str);
    return add_node_end(&(info->alias), str, 0) == NULL;
}

/**
 * print_alias - Print an alias from the list.
 * @node: Pointer to a list node containing the alias.
 *
 * Return: 0 on success, 1 on failure.
 */


int print_alias(list_t *node)
{
    char *p = NULL;
    char *a; /* Declare 'a' outside of the for loop */

    if (node)
    {
        p = _strchr(node->str, '=');
        
        for (a = node->str; a <= p; a++)
            _putchar(*a);

        _putchar('\'');
        _puts(p + 1);
        _puts("'\n");
        return 0;
    }
    return 1;
}

/**
 * _myalias - Handle the 'alias' command.
 * @info: Pointer to info_t structure.
 *
 * Return: 0 on success.
 */
int _myalias(info_t *info)
{
    char *p = NULL;
    list_t *node = NULL;
    int i = 1;  /* Declare 'i' outside the 'for' loop */

    if (info->argc == 1)
    {
        node = info->alias;
        while (node)
        {
            print_alias(node);
            node = node->next;
        }
        return 0;
    }

    for (; info->argv[i]; i++)
    {
        p = _strchr(info->argv[i], '=');
        if (p)
        {
            set_alias(info, info->argv[i]);
        }
        else
        {
            print_alias(node_starts_with(info->alias, info->argv[i], '='));
        }
    }

    return 0;
}

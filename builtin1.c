#include "shell.h"

/**
 * _myhistory - displays history list one command by line, preceded
 *              with line numbers, starting at 0.
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: Always 0
 */
int _myhistory(info_t *info)
{
	print_list(info->history);
	return (0);
}

/**
 * unset_alias - This sets the alias to string
 * @info: parameter struct
 * @str: this is the string alias
 *
 * Return: Always 0 on success, 1 on error
 */
int unset_alias(info_t *info, char *str)
{
	char *b, x;
	int ret;

	b = _strchr(str, '=');
	if (!b)
		return (1);
	x = *b;
	*b = 0;
	ret = delete_node_at_index(&(info->alias),
			get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
	*p = x;
	return (ret);
}
/**
 * set_alias - This will set alias to string
 * @info: parameter struct
 * @str: this is the string alias
 *
 * Return: Always 0 on success, 1 on error
 */
int set_alias(info_t *info, char *str)
{
	char *b;

	b = _strchr(str, '=');
	if (!b)
		return (1);
	if (!*++b)
		return (unset_alias(info, str));

	unset_alias(info, str);
	return (add_node_end(&(info->alias), str, 0) == NULL);
}

/**
 * print_alias - This will print an alias string
 * @node: the alias node
 *
 * Return: Always 0 on success, 1 on error
 */
int print_alias(list_t *node)
{
	char *b = NULL, *f = NULL;

	if (node)
	{
		b = _strchr(node->str, '=');
		for (f = node->str; f <= b; f++)
			_putchar(*a);
		_putchar('\'');
		_puts(b + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * _myalias - This will mimic the alias builtin
 * @info: This structure contains potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: Always 0
 */
int _myalias(info_t *info)
{
	int a = 0;
	char *b = NULL;
	list_t *node = NULL;

	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			print_alias(node);
			node = node->next;
		}
		return (0);
	}
	for (a = 1; info->argv[a]; a++)
	{
		b = _strchr(info->argv[a], '=');
		if (b)
			set_alias(info, info->argv[a]);
		else
			print_alias(node_starts_with(info->alias, info->argv[a], '='));
	}

	return (0);
}

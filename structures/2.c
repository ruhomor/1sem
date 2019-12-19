#include <stdlib.h>
#include <stdio.h>

typedef	struct		s_list
{
	int		n;
	struct s_list	*next;
}			list;
	
list	*create_elem(int n) //ne void
{
	list	*new;

	if (!(new = (list*)malloc(sizeof(*new))))
		return (NULL);
	new->n = n;
	new->next = NULL;
	return (new);
}

list	*add_s(list *root, int n) //ne void
{
	list *newr;

	if ((newr = create_elem(n)))
	{
		newr->next = root;
		return (newr);
	}
	return (NULL);
}

list	*add_e(list *elem, int n) //void
{
	while (elem->next)
		elem = elem->next;
	if ((elem->next = create_elem(n)))
		return (elem->next);
	return (NULL);
}

int	lst_add_after(list *lst, int key1, int keynew)
{
	list	*new;
	list	*buf;

	if (lst->n == key1)
	{
		new = create_elem(keynew);
		buf = lst->next;
		lst->next = new;
		new->next = buf;
		return (1);
	}
	return (0);
}

int	lst_display(list *lst, int key1, int keynew)
{
	key1 = 0; //useless
	keynew = 0; //useless
	if (lst)
	{
		printf("item: %d ", lst->n);
		return (0);
	}
	return (1);
}

int	lst_del(list **p, list *el, int key, int keynew)
{
	key = 0; //useless
	keynew = 0; //useless;

	if (*p == el)
	{
		if (el->next == NULL)
		{
			printf("deleted: %d\n", el->n);
			free(el);
			*p = NULL;
			return (1);
		}
		*p = NULL;
		return (0);
	}
	if (el->next == NULL)
	{
		printf("deleted: %d, %d\n", (*p)->n, el->n);
		free(*p);
		free(el);
		*p = NULL;
		return (1);
	}
	else
	{
		printf("deleted: %d\n", (*p)->n);
		free(*p);
		*p = NULL;
		return (0);
	}
}

int	lst_add_before(list **p, list *el, int key1, int keynew)
{
	list    *new;
	list	*prev;

	if (*p == el)
		prev = NULL;
	else
		prev = *p;
	if (el->n == key1)
	{
		new = create_elem(keynew);
		new->next = el;
		if (prev)
			prev->next = new;
		else
			*p = new;
		return (1);
	}
	return (0);
}

void	lst_map(list *elem, int key, int keynew, int (*f)(list *lst, int key1, int keynew))
{
	int	end = 1;

	end = (*f)(elem, key, keynew);
	while ((!(end)) && elem->next)
	{
		end = (*f)(elem->next, key, keynew);
		elem = elem->next;
	}
}

int	del_s(list **root)
{
	list	*tmp;

	if (root)
	{
		tmp = *root;
		if (tmp->next == NULL)
		{
			free(tmp);
			*root = NULL;
			return (1);
		}
		*root = tmp->next;
		free(tmp);
		return (1);
	}
	return (-1);
}

int	del_e(list **root)
{
	list	*tmp;
	list	*tmp2;

	if (root)
	{
		tmp = *root;
		if (tmp->next == NULL)
		{
			free(tmp);
			*root = NULL;
			return (1);
		}
		while ((tmp->next)->next)
			tmp = tmp->next;
		tmp2 = tmp->next;
		tmp->next = NULL;
		free(tmp2);
		return (1);
	}
	return (-1);
}

int	lst_keydel(list **root, list *lst, int key, int keynew)
{
	keynew = 0; //useless

	if (key == lst->n)
	{
		if (*root == lst)
			del_s(root);
		else
		{
			(*root)->next = lst->next;
			free(lst);
		}
		return (1);
	}
	return (0);
}

void	lst_map_root(list **root, list *elem, int key, int keynew, int (*f)(list **root, list *lst, int key1, int keynew))
{
	int	end = 1;
	list	*tmp;

	end = (*f)(root, elem, key, keynew);
	while ((!(end)) && elem->next)
	{
		tmp = elem->next;
		end = (*f)(&elem, elem->next, key, keynew);
		elem = tmp;
	}
}

int	main()
{
	int	(*after)(list *, int, int);
	int	(*before)(list **, list *, int, int);
	int	(*delete_list)(list **, list *, int, int);
	int	(*display)(list *, int, int);
	int	(*keydel)(list **, list *, int, int);
	list	*root;
	int	key;
	int	keynew;
	int	cmd = 0;

	keydel = lst_keydel;
	after = lst_add_after;
	before = lst_add_before;
	display = lst_display;
	delete_list = lst_del;

	printf("Команды\n1 - создать список\n2 - вывести список\n3 - добавить элемент в конец\n4 - добавить элемент в начало\n5 - добавить элемент после ключа\n6 - добавить элемент до ключа\n7 - удалить список\n8 - удалить элемент по ключу\n9 - удалить элемент из начала\n10 - удалить элемент с конца\n");
	while (1)
	{
		scanf("%d", &cmd);
		switch(cmd)
		{
			case 1:
				printf("ключ: ");
				scanf("%d", &key);
				printf("\n");
				root = create_elem(key);
				break;
			case 2:
				lst_map(root, 0, 0, display);
				printf("\n");
				break;
			case 3:
				printf("ключ: ");
				scanf("%d", &key);
				printf("\n");
				add_e(root, key);
				break;
			case 4:
				printf("ключ: ");
				scanf("%d", &key);
				printf("\n");
				root = add_s(root, key);
				break;
			case 5:
				printf("новый ключ: ");
				scanf("%d", &keynew);
				printf("\n");
				printf("ключ: ");
				scanf("%d", &key);
				printf("\n");
				lst_map(root, key, keynew, after);
				break;
			case 6:
				printf("новый ключ: ");
				scanf("%d", &keynew);
				printf("\n");
				printf("ключ: ");
				scanf("%d", &key);
				printf("\n");
				lst_map_root(&root, root, key, keynew, before);
				break;
			case 7:
				lst_map_root(&root, root, 0, 0, delete_list);
				break;
			case 8:
				printf("ключ: ");
				scanf("%d", &key);
				printf("\n");
				lst_map_root(&root, root, key, 0, keydel);
				break;
			case 9:
				del_s(&root);
				break;
			case 10:
				del_e(&root);
				break;
		}
	}
	return (0);
}

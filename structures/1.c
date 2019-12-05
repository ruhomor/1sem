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
		printf("item: %d\n", lst->n);
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
			free(el);
			*p = NULL;
			return (1);
		}
		return (0);
	}
	if (el->next == NULL)
	{
		free(*p);
		free(el);
		p = NULL;
		return (1);
	}
	else
	{
		free(*p);
		p = NULL;
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
	while (elem->next && (!(end)))
	{
		end = (*f)(elem->next, key, keynew);
		elem = elem->next;
	}
}

void	lst_map_root(list **root, list *elem, int key, int keynew, int (*f)(list **root, list *lst, int key1, int keynew))
{
	int	end = 1;

	end = (*f)(root, elem, key, keynew);
	while (elem->next && (!(end)))
	{
		end = (*f)(&elem, elem->next, key, keynew);
		elem = elem->next;
	}
}

int	main()
{
	int	(*after)(list *, int, int);
	int	(*before)(list **, list *, int, int);
	int	(*delete_list)(list **, list *, int, int);
	int	(*display)(list *, int, int);
	list	*root;
	list	*iter;

	after = lst_add_after;
	before = lst_add_before;
	display = lst_display;
	delete_list = lst_del;

	root = create_elem(10);
	iter = root;
	lst_map(root, 0, 0, display);
	lst_map(root, 10, 2, after);
	lst_map(root, 0, 0, display);
	lst_map(root, 10, 3, after);
	lst_map(root, 0, 0, display);
	lst_map(root, 2, 12, after);
	lst_map(root, 0, 0, display);
	lst_map_root(&root, root, 10, -228, before);
	lst_map(root, 0, 0, display);
	lst_map_root(&root, root, 12, 999999, before);
	lst_map(root, 0, 0, display);
	lst_map_root(&root, root, 0, 0, delete_list);
	printf("\n");
	lst_map(root, 0, 0, display);
	printf("\n");
	return (0);
}

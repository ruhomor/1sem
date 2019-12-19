typedef struct s_tree
{
	struct s_tree	*parent;
	struct s_tree	*right;
	struct s_tree	*left;
	int		num;
} tree;

tree	*create_tree(int num)
{
	tree	*new;

	if (!(new = (tree*)malloc(sizeof(*new))))
		return (NULL);
	new->num = num;
	new->parent = NULL;
	new->left = NULL;
	new->right = NULL;
	return (new);
}

int	main()
{
	tree	*root;

	root = create_tree(42);
	
}

#include "hash_tables.h"

/**
 * shash_table_create - function that creates a php hash table
 * @size: size of input
 * Return: pointer to newly-created hash table
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *create = NULL;

	if (!size)
		return (NULL);

	create = calloc(1, sizeof(shash_table_t));
	if (!create)
		return (NULL);

	create->size = size;
	create->array = calloc(size, sizeof(shash_node_t *));
	if (!create->array)
	{
		free(create);
		return (NULL);
	}
	return (create);
}

/**
 * shash_table_set - adds an element to the hash table
 * @ht: hash table to add or update key/value for
 * @key: key, cannot be empty
 * @value: value associated with key. must be duplicated
 * Return: 1 on success, 0 otherwise
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	unsigned long int i;
	shash_node_t *head = NULL, *new = NULL;

	if (!ht || !key || !value)
		return (0);

	i = key_index((const unsigned char *)key, ht->size);

	head = ht->array[i];
	while (head)
	{
		if (strcmp(head->key, key) == 0)
		{
			free(head->value);
			head->value = strdup(value);
			if (!head->value)
				return (0);
			else
				return (1);
		}
		head = head->next;
	}

	new = malloc(sizeof(shash_node_t));
	if (!new)
		return (0);

	new->key = strdup(key);
	if (!new->key)
	{
		free(new);
		return (0);
	}

	new->value = strdup(value);
	if (!new->value)
	{
		free(new);
		return (0);
	}
	new->next = ht->array[i];
	ht->array[i] = new;
	shash_sort(ht, new);
	return (1);
}

/**
 * shash_sort - sorts hash table
 * @ht: hash table
 * @node: node to sort
 * Return: void
 */
void shash_sort(shash_table_t *ht, shash_node_t *node)
{
	shash_node_t *head;

	if (!ht)
		return;

	head = ht->shead;
	if (!head || strcmp(node->key, head->key) < 0)
	{
		node->next = head;
		ht->shead = node;
		if (head)
			head->sprev = node;
		else
			ht->stail = node;
		return;
	}

	while (head->snext && strcmp(node->key, head->snext->key) >= 0)
	{
		head = head->snext;
	}
	node->sprev = head;
	node->snext = head->snext;

	if (head->snext)
		head->snext->sprev = node;
	else
		ht->stail = node;
	head->snext = node;
}



/**
 * shash_table_get - retrieves a value associated with a key
 * @ht: hash table to look into
 * @key: key you are looking for
 * Return: value associated with the element
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	unsigned int i = 0;
	shash_node_t *entry = NULL;

	if (!ht || !key || !*key)
		return (NULL);

	i = key_index((const unsigned char *)key, ht->size);

	entry = ht->array[i];
	while (entry)
	{
		if (strcmp(key, entry->key) == 0)
			return (entry->value);
		entry = entry->next;
	}
	return (NULL);
}

/**
 * shash_table_print - prints a hash table
 * @ht: hash table to print
 * Return: void
 */
void shash_table_print(const shash_table_t *ht)
{
	unsigned int flag = 1;
	shash_node_t *node;

	if (ht)
	{
		printf("{");
		node = ht->shead;
		while (node)
		{
			if (!flag)
				printf(", ");
			printf("'%s': '%s'", node->key, node->value);
			flag = 0;
			node = node->snext;
		}
		printf("}\n");
	}
}

/**
 * shash_table_print_rev - prints a hash table in reverse
 * @ht: hash table to print
 * Return: void
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	unsigned long int flag = 0;
	shash_node_t *node = NULL;

	printf("{");
	node = ht->stail;
	while (node)
	{
		if (!flag)
			printf(", ");
		printf("'%s': '%s'", node->key, node->value);
		flag = 0;
		node = node->sprev;
	}
	printf("}\n");
}

/**
 * shash_table_delete - deletes a hash table
 * @ht: hash table to delete
 * Return: void
 */
void shash_table_delete(shash_table_t *ht)
{
	unsigned int i = 0;
	shash_node_t *node, *temp;

	if (!ht)
		return;

	for (i = 0; i < ht->size; i++)
	{
		node = ht->array[i];
		while (node)
		{
			temp = node;
			node = node->next;
			free(temp->key);
			free(temp->value);
			free(temp);
		}
	}
	free(ht->array);
	free(ht);
}

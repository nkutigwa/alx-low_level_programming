#include "hash_tables.h"

/**
 * shash_table_create - create a sorted hash table
 * @size: size for the table
 *
 * Return: shash table
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *table = NULL;

	if (size == 0)
		return (NULL);

	table = malloc(sizeof(shash_table_t));
	if (table == NULL)
		return (NULL);

	table->array = calloc(size, sizeof(shash_node_t *));
	if (table->array == NULL)
	{
		free(table);
		return (NULL);
	}

	table->size = size;
	table->shead = NULL;
	table->stail = NULL;

	return (table);
}

/**
 * shash_table_set - set a node in a shash_table
 * @ht: shash_table
 * @key: key for the node
 * @value: value for the node
 *
 * Return: 1 on success
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	unsigned long int id;
	shash_node_t *s_list = NULL;

	if (ht == NULL || !strcmp(key, "") || key == NULL)
		return (0);

	id = key_index((unsigned char *) key, ht->size);
	if (ht->array[id] != NULL)
	{
		while (ht->array[id])
		{
			if (strcmp(ht->array[id]->key, key) == 0)
			{
				free(ht->array[id]->value);
				ht->array[id]->value = strdup(value);
				return (1);
			}
			ht->array[id] = ht->array[id]->next;
		}

		s_list = malloc(sizeof(shash_node_t));
		if (s_list == NULL)
			return (0);
		s_list->key = strdup(key);
		s_list->value = strdup(value);
		s_list->next = ht->array[id];
		ht->array[id] = s_list;
		s_list->sprev = NULL;
		s_list->snext = NULL;
		return (1);
	}
	else
		set_new_index(ht, key, value, id);
	return (1);
}

/**
 * shash_table_get - get a node from a shash_table
 * @ht: shash_table
 * @key: key of the node
 *
 * Return: value of the node
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	shash_node_t *tmp = NULL;
	unsigned long id;

	if (ht == NULL || !key)
		return (NULL);

	id = key_index((unsigned char *) key, ht->size);

	if (ht->array[id] != NULL)
	{
		tmp = ht->array[id];
		while (tmp)
		{
			if (strcmp(key, tmp->key) == 0)
				return (strdup(tmp->value));
			tmp = tmp->next;
		}
	} return (NULL);
}

/**
 * shash_table_print - print a shash_table
 * @ht: shash_table
 *
 * Return: None
 */
void shash_table_print(const shash_table_t *ht)
{
	int flat = 0;
	shash_node_t *tmp = NULL;

	if (ht == NULL)
		return;

	if (ht->shead)
	{
		tmp = ht->shead;

		printf("{");
		while (tmp)
		{
			if (flat > 0)
				printf(", ");
			printf("'%s' : '%s'", tmp->key, tmp->value);
			flat++;
			tmp = tmp->snext;
		}
		printf("}\n");
	}
}

/**
 * shash_table_print_rev - print a shash_table in reverse
 * @ht: shash_table
 *
 * Return: None
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	int flat = 0;
	shash_node_t *tmp = NULL;

	if (ht == NULL)
		return;

	if (ht->stail)
	{
		tmp = ht->stail;

		printf("{");
		while (tmp->sprev != NULL)
		{
			if (flat > 0)
				printf(",");
			printf("'%s' : '%s'", tmp->key, tmp->value);
			flat++;
			tmp = tmp->sprev;
		}
		printf(", '%s' : '%s'", tmp->key, tmp->value);
		printf("}\n");
	}

}

/**
 * set_new_index - set a new index in shash_table
 * @ht: shash_table
 * @key: key for the node
 * @value: value for the node
 * @id: id
 *
 * Return: shash table
 */
int set_new_index(shash_table_t *ht, const char *key, const char *value, unsigned long id)
{
	shash_node_t *tmp = NULL, *s_list = NULL;

	if (ht == NULL || !key)
		return (0);

	s_list = malloc(sizeof(shash_node_t));
	if (s_list == NULL)
		return (0);

	s_list->key = strdup(key);
	s_list->value = strdup(value);
	s_list->next = ht->array[id];
	ht->array[id] = s_list;

	if (ht->shead == NULL)
	{
		ht->shead = s_list;
		ht->stail = s_list;
	}
	else
	{
		tmp = ht->shead;

		while (tmp)
		{
			if (strcmp(s_list->key, tmp->key) <= 0)
			{
				s_list->snext = tmp;
				s_list->sprev = tmp->sprev;
				if (tmp->sprev == NULL)
				{
					ht->shead = s_list;
				}
				else
				{
					tmp->sprev->snext = s_list;
				}
				tmp->sprev = s_list;
				break;
			}
			tmp = tmp->snext;
		}

		if (!tmp)
		{
			ht->stail->snext = s_list;
			s_list->sprev = ht->stail;
			ht->stail = s_list;
		}
	}
	return (1);
}

/**
 * shash_table_delete - delete a sorted hash table
 * @ht: shash_table
 *
 * Return: None
 */
void shash_table_delete(shash_table_t *ht)
{
	shash_node_t *tmp = NULL, *del = NULL;

	tmp = ht->shead;

	while (tmp != NULL)
	{
		del = tmp;
		tmp = tmp->snext;
		free(del->key);
		free(del->value);
		free(del);
	}
	free(ht->array);
	free(ht);
}

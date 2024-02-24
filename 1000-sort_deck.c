#include "deck.h"
#include <stdio.h>
/**
 *_strcmp - A funtion that compares two strings
 *@str1: first string
 *@str2: second string
 *Return: 1 str1 and str2 is equal, 0 they are not equal
 */
int _strcmp(const char *str1, char *str2)
{
	size_t i = 0;

	if (str1 == '\0')
		return (0);
	while (str1[i])
	{
		if (str1[i] != str2[i])
			return (0);
		i++;
	}
	if (str2[i] && str1[i] == '\0')
		return (0);
	return (1);
}
/**
 * get_card_position - gets the position based on card you put in
 * @node: node represents the card
 * Return: returns the card position
 */
int get_card_position(deck_node_t *node)
{
	int value;

	value = (*node).card->value[0] - '0';
	if (value > 57 || value < 50)
	{
		if (_strcmp((*node).card->value, "Ace") == 1)
			value = 1;
		else if (_strcmp((*node).card->value, "10") == 1)
			value = 10;
		else if (_strcmp((*node).card->value, "Jack") == 1)
			value = 11;
		else if (_strcmp((*node).card->value, "Queen") == 1)
			value = 12;
		else if (_strcmp((*node).card->value, "King") == 1)
			value = 13;
	}
	value += (*node).card->kind * 13;
	return (value);
}
/**
 *swap_card - swaps a card for its previous one
 *@card: the card
 *@deck: the card deck
 *Return: returns a pointer to a card which was entered
 */
deck_node_t *swap_card(deck_node_t *card, deck_node_t **deck)
{
	deck_node_t *back = card->prev, *current = card;
	/*NULL, 29, 48, 19, 71, 13, NULL*/

	back->next = current->next;
	if (current->next)
		current->next->prev = back;
	current->next = back;
	current->prev = back->prev;
	back->prev = current;
	if (current->prev)
		current->prev->next = current;
	else
		*deck = current;
	return (current);
}

/**
 * insertion_sort_deck - A function that sorts a doubly linked deck
 * of integers in ascending order using the Insertion sort algorithm
 * @deck: Doubly linked deck to sort
 */
void insertion_sort_deck(deck_node_t **deck)
{
	int prev_value, current_value;
	deck_node_t *node;

	if ((*deck)->next == NULL || deck == NULL)
		return;
	node = (*deck)->next;
	while (node)
	{
		/* preparing previous value */
		if (node->prev)
		{
			prev_value = get_card_position((node->prev));
			current_value = get_card_position(node);
		}
		while ((node->prev) && (prev_value > current_value))
		{
			prev_value = get_card_position((node->prev));
			current_value = get_card_position(node);
			node = swap_card(node, deck);

		}
		node = node->next;
	}
}
/**
 * sort_deck - A function that sorts a deck you put in using
 * insertion sort algorithm
 * @deck: the deck
 */
void sort_deck(deck_node_t **deck)
{
	insertion_sort_deck(deck);
}

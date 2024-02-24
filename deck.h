#ifndef DECK_H
#define DECK_H

/**
 * enum kind_e - kind of card
 * @SPADE: spade kind
 * @HEART: heart kind
 * @CLUB: club kind
 * @DIAMOND: diamond kind
 */
typedef enum kind_e
{
	SPADE = 0,
	HEART,
	CLUB,
	DIAMOND
} kind_t;

/**
 * struct card_s - The playing card
 *
 * @value: The value of the card
 * from "Ace" to "King"
 * @kind: the kind of card
 */
typedef struct card_s
{
	const char *value;
	const kind_t kind;
} card_t;

/**
 * struct deck_node_s - the Deck of card
 *
 * @card: A Pointer to the card on the node
 * @prev: A Pointer to the previous node on the list
 * @next: A Pointer to the next node on the list
 */
typedef struct deck_node_s
{
	const card_t *card;
	struct deck_node_s *prev;
	struct deck_node_s *next;
} deck_node_t;

void sort_deck(deck_node_t **deck);
#endif

#include <stdio.h>
#include "character.h"

void print_status(Character *c) {
	printf("%s - HP: %d | Estus: %d\n", c->name, c->hp, c->estus);
}

int is_alive(Character *c) {
	return c->hp > 0;
}

void init_character(Character *c, char *name, int hp, int damage, int estus) {
	c->name = name;
	c->hp = hp;
	c->max_damage = damage;
	c->estus = estus;
	c->rolled = 0;
}

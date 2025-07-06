#include <stdio.h>
#include "character.h"

void print_status(Character *c) {
	printf("%s - HP: %d | Estus: %d\n", c->name, c->hp, c->estus);
	printf("Weapon: %s | Spell: %s (%d uses)\n",
		c->weapon ? c->weapon : "None",
		c->spell ? c->spell : "None",
		c->spell_uses);
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
	c->weapon = "Bare Hands";
	c->spell = "None";
	c->spell_uses = 0;
}

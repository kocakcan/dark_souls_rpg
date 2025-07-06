#ifndef CHARACTER_H
#define CHARACTER_H

typedef struct {
	char *name;
	int hp;
	int max_damage;
	int estus;
	int rolled;
	char *weapon;
	char *spell;
} Character;

void print_status(Character *c);
int is_alive(Character *c);
void init_character(Character *c, char *name, int hp, int damage, int estus);

#endif

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
  int spell_uses;
  char *spell_type; /* Pyromancy, Sorcery, Miracle */
  int burning;      /* Turns left for Fireball's DoT */
  int str;          /* Strength */
  int intel;        /* Intelligence */
  int fth;          /* Faith */
} Character;

void print_status(Character *c);
int is_alive(Character *c);
void init_character(Character *c, char *name, int hp, int damage, int estus);

#endif

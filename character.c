#include "character.h"
#include <stdio.h>
#include <string.h>

void print_status(Character *c) {
  if (strcmp(c->weapon, "Staff") == 0)
    printf("📖 Focused on magic.\n");
  if (c->burning > 0)
    printf("🔥 Burning (%d turns left)\n", c->burning);
  printf("STR: %d | INT: %d | FTH: %d\n", c->str, c->intel, c->fth);
  printf("%s - HP: %d | Estus: %d\n", c->name, c->hp, c->estus);
  printf("Weapon: %s | Spell: %s (%d uses)\n", c->weapon ? c->weapon : "None",
         c->spell ? c->spell : "None", c->spell_uses);
}

int is_alive(Character *c) { return c->hp > 0; }

void init_character(Character *c, char *name, int hp, int damage, int estus) {
  c->name = name;
  c->hp = hp;
  c->max_damage = damage;
  c->estus = estus;
  c->rolled = 0;
  c->weapon = "Bare Hands";
  c->spell = "None";
  c->spell_uses = 0;
  c->spell_type = "None";
  c->burning = 0;
  c->str = 0;
  c->intel = 0;
  c->fth = 0;
}

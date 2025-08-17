#include "input.h"
#include "combat.h"
#include <stdio.h>

void player_turn(Character *player, Character *boss) {
  printf("\nYour turn:\n");
  printf("1. Attack\n");
  printf("2. Roll\n");
  printf("3. Drink Estus (%d left)\n", player->estus);
  printf("4. Cast Spell (%s, %d left)\n", player->spell, player->spell_uses);
  printf("> ");

  int choice;
  scanf("%d", &choice);

  switch (choice) {
  case 1:
    attack(player, boss);
    break;
  case 2:
    roll(player);
    break;
  case 3:
    drink_estus(player);
    break;
  case 4:
    cast_spell(player, boss);
    break;
  default:
    printf("Invalid choice. You hesitate...\n");
  }
}

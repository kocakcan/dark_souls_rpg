#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "character.h"
#include "class.h"
#include "constants.h"
#include "combat.h"
#include "input.h"

#define MAX_HP	100

int main(void) {
	srand(time(NULL));

	Character player;
	choose_class(&player);

	Character boss;
	init_character(&boss, "Manus, Father of the Abyss", MAX_HP + 50, 20, 0);

	printf("⚔️  %s vs. %s begins!\n", player.name, boss.name);

	while (is_alive(&player) && is_alive(&boss)) {
		apply_status_effects(&player);
		apply_status_effects(&boss);
		printf("\n--- BATTLE STATUS ---\n");
		print_status(&player);
		print_status(&boss);

		player_turn(&player, &boss);

		if (!is_alive(&boss)) break;

		printf("\n👹 %s's turn...\n", boss.name);
		attack(&boss, &player);
	}

	if (is_alive(&player))
		printf("\n🏆 Victory! %s has defeated %s!\n", player.name, boss.name);
    	else
		printf("\n💀 You Died. %s has fallen to %s...\n", player.name, boss.name);

    return 0;
}

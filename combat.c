#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "constants.h"
#include "combat.h"

#define ESTUS_HEAL	30
#define ROLL_CHANCE	50
#define CRIT_CHANCE	20

int random_percent(void) {
	return rand() % 100;
}

void attack(Character *attacker, Character *defender) {
	if (defender->rolled) {
		printf("🌀 %s dodged the attack!\n", defender->name);
		defender->rolled = 0;
		return;
	}

	int damage = attacker->max_damage;

	// Weapon-specific bonus
	if (strcmp(attacker->weapon, "Greatsword") == 0) {
		damage += 5;
		printf("💥 Heavy strike from the Greatsword!\n");
	} else if (strcmp(attacker->weapon, "Axe") == 0) {
		damage += rand() % 6;	/* spiky unpredictable */
		printf("🪓 The Axe hits with wild force!\n");
	} else if (strcmp(attacker->weapon, "Staff") == 0) {
		damage -= 5;
		printf("📏 Weak melee attack with the Staff.\n");		
	}

	printf("🗡️  %s attacks %s for %d damage!\n",
           attacker->name, defender->name, damage);

	defender->hp -= damage;
	if (defender->hp < 0) defender->hp = 0;
}

void drink_estus(Character *c) {
	if (c->estus > 0) {
		c->hp += ESTUS_HEAL;
		if (c->hp > MAX_HP) c->hp = MAX_HP;
		c->estus--;
		printf("🧪 %s drinks Estus and restores %d HP!\n", c->name, ESTUS_HEAL);
    	} else {
		printf("❌ No Estus left!\n");
	}
}

void roll(Character *c) {
	if (random_percent() < ROLL_CHANCE) {
		printf("🌀 %s performs a perfect roll and will dodge the next attack!\n", c->name);
		c->rolled = 1;
	} else {
		printf("💢 %s tries to roll but stumbles!\n", c->name);
		c->rolled = 0;
	}
}

void cast_spell(Character *caster, Character *target) {
    if (caster->spell_uses <= 0) {
        printf("❌ No spell uses left!\n");
        return;
    }

    if (!caster->spell) {
        printf("🌀 No spell equipped.\n");
        return;
    }

    if (strcmp(caster->spell, "Soul Arrow") == 0) {
        int damage = 25 + rand() % 10;
        printf("✨ %s casts Soul Arrow! %s takes %d magic damage!\n",
               caster->name, target->name, damage);
        target->hp -= damage;
    } else if (strcmp(caster->spell, "Fireball") == 0) {
        int damage = 20 + rand() % 15;
        printf("🔥 %s hurls a Fireball! %s is scorched for %d damage!\n",
               caster->name, target->name, damage);
        target->hp -= damage;
    } else {
        printf("🌀 No valid spell found.\n");
        return;
    }

    if (target->hp < 0) target->hp = 0;
    caster->spell_uses--;
}

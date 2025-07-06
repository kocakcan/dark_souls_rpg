#ifndef COMBAT_H
#define COMBAT_H

#include "character.h"

void attack(Character *attacker, Character *defender);
void drink_estus(Character *c);
void roll(Character *c);
void cast_spell(Character *caster, Character *target);
void apply_status_effects(Character *c);

#endif

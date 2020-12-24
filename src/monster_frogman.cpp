/*-------------------------------------------------------------------------------

	BARONY
	File: monster_frogman.cpp
	Desc: implements all of the frogman monster's code

	Copyright 2013-2016 (c) Turning Wheel LLC, all rights reserved.
	See LICENSE for details.

-------------------------------------------------------------------------------*/

#include "main.hpp"
#include "game.hpp"
#include "stat.hpp"
#include "entity.hpp"
#include "items.hpp"
#include "monster.hpp"
#include "sound.hpp"
#include "net.hpp"
#include "collision.hpp"
#include "player.hpp"

void initFrogman(Entity* my, Stat* myStats)
{
	int c;
	node_t* node;

	my->initMonster(1500);

	if (multiplayer != CLIENT)
	{
		MONSTER_SPOTSND = 709;
		MONSTER_SPOTVAR = 1;
		MONSTER_IDLESND = -1;
		MONSTER_IDLEVAR = 1;
	}
	if (multiplayer != CLIENT && !MONSTER_INIT)
	{
		if (myStats != NULL)
		{
			if (!myStats->leader_uid)
			{
				myStats->leader_uid = 0;
			}

			// apply random stat increases if set in stat_shared.cpp or editor
			setRandomMonsterStats(myStats);

			// generate 6 items max, less if there are any forced items from boss variants
			int customItemsToGenerate = ITEM_CUSTOM_SLOT_LIMIT;

			// boss variants
			if (rand() % 50 || my->flags[USERFLAG2] || myStats->MISC_FLAGS[STAT_FLAG_DISABLE_MINIBOSS])
			{
			}
			else
			{
				strcpy(myStats->name, "Thumpus the Frogman");
				for (c = 0; c < 3; c++)
				{
					Entity* entity = summonMonster(GNOME, my->x, my->y);
					if (entity)
					{
						entity->parent = my->getUID();
					}
				}
				myStats->HP *= 2;
				myStats->MAXHP *= 2;
				myStats->OLDHP = myStats->HP;
				myStats->GOLD += 300;
				myStats->LVL += 10;
			}

			// random effects
			if (rand() % 4 < 4)
			{
				//myStats->EFFECTS[EFF_ASLEEP] = true;
				//myStats->EFFECTS_TIMERS[EFF_ASLEEP] = 1800 + rand() % 3600;
				//myStats->EFFECTS[EFF_PARALYZED] = true;
				//myStats->EFFECTS_TIMERS[EFF_PARALYZED] = 1800 + rand() % 3600;
			}

			// generates equipment and weapons if available from editor
			createMonsterEquipment(myStats);

			// create any custom inventory items from editor if available
			createCustomInventory(myStats, customItemsToGenerate);

			// count if any custom inventory items from editor
			int customItems = countCustomItems(myStats); //max limit of 6 custom items per entity.

			// count any inventory items set to default in edtior
			int defaultItems = countDefaultItems(myStats);

			my->setHardcoreStats(*myStats);

			// generate the default inventory items for the monster, provided the editor sprite allowed enough default slots
			switch (defaultItems)
			{
			case 6:
			case 5:
			case 4:
			case 3:
			case 2:
			case 1:
				if (rand() % 3 == 0)
				{
					int i = 1 + rand() % 3;
					for (c = 0; c < i; c++)
					{
						Category cat = static_cast<Category>(rand() % (NUMCATEGORIES - 1));
						newItem(static_cast<ItemType>(itemLevelCurve(cat, 0, currentlevel + 10)), static_cast<Status>(1 + rand() % 4), -1 + rand() % 3, 1, rand(), false, &myStats->inventory);
					}
				}
				break;
			default:
				break;
			}
		}
	}

	// torso
	Entity* entity = newEntity(1501, 0, map.entities, nullptr); //Limb entity.
	entity->sizex = 4;
	entity->sizey = 4;
	entity->skill[2] = my->getUID();
	entity->flags[PASSABLE] = true;
	entity->flags[NOUPDATE] = true;
	entity->flags[USERFLAG2] = my->flags[USERFLAG2];
	entity->focalx = limbs[FROGMAN][1][0]; // 0
	entity->focaly = limbs[FROGMAN][1][1]; // 0
	entity->focalz = limbs[FROGMAN][1][2]; // 0
	entity->behavior = &actFrogmanLimb;
	entity->parent = my->getUID();
	node = list_AddNodeLast(&my->children);
	node->element = entity;
	node->deconstructor = &emptyDeconstructor;
	node->size = sizeof(Entity*);
	my->bodyparts.push_back(entity);

	// right leg
	entity = newEntity(1505, 0, map.entities, nullptr); //Limb entity.
	entity->sizex = 4;
	entity->sizey = 4;
	entity->skill[2] = my->getUID();
	entity->flags[PASSABLE] = true;
	entity->flags[NOUPDATE] = true;
	entity->flags[USERFLAG2] = my->flags[USERFLAG2];
	entity->focalx = limbs[FROGMAN][2][0]; // 1
	entity->focaly = limbs[FROGMAN][2][1]; // 0
	entity->focalz = limbs[FROGMAN][2][2]; // 2
	entity->behavior = &actFrogmanLimb;
	entity->parent = my->getUID();
	node = list_AddNodeLast(&my->children);
	node->element = entity;
	node->deconstructor = &emptyDeconstructor;
	node->size = sizeof(Entity*);
	my->bodyparts.push_back(entity);

	// left leg
	entity = newEntity(1504, 0, map.entities, nullptr); //Limb entity.
	entity->sizex = 4;
	entity->sizey = 4;
	entity->skill[2] = my->getUID();
	entity->flags[PASSABLE] = true;
	entity->flags[NOUPDATE] = true;
	entity->flags[USERFLAG2] = my->flags[USERFLAG2];
	entity->focalx = limbs[FROGMAN][3][0]; // 1
	entity->focaly = limbs[FROGMAN][3][1]; // 0
	entity->focalz = limbs[FROGMAN][3][2]; // 2
	entity->behavior = &actFrogmanLimb;
	entity->parent = my->getUID();
	node = list_AddNodeLast(&my->children);
	node->element = entity;
	node->deconstructor = &emptyDeconstructor;
	node->size = sizeof(Entity*);
	my->bodyparts.push_back(entity);

	// right arm
	entity = newEntity(1503, 0, map.entities, nullptr); //Limb entity.
	entity->sizex = 4;
	entity->sizey = 4;
	entity->skill[2] = my->getUID();
	entity->flags[PASSABLE] = true;
	entity->flags[NOUPDATE] = true;
	entity->flags[USERFLAG2] = my->flags[USERFLAG2];
	entity->focalx = limbs[FROGMAN][4][0]; // -.25
	entity->focaly = limbs[FROGMAN][4][1]; // 0
	entity->focalz = limbs[FROGMAN][4][2]; // 3
	entity->behavior = &actFrogmanLimb;
	entity->parent = my->getUID();
	node = list_AddNodeLast(&my->children);
	node->element = entity;
	node->deconstructor = &emptyDeconstructor;
	node->size = sizeof(Entity*);
	my->bodyparts.push_back(entity);

	// left arm
	entity = newEntity(1502, 0, map.entities, nullptr); //Limb entity.
	entity->sizex = 4;
	entity->sizey = 4;
	entity->skill[2] = my->getUID();
	entity->flags[PASSABLE] = true;
	entity->flags[NOUPDATE] = true;
	entity->flags[USERFLAG2] = my->flags[USERFLAG2];
	entity->focalx = limbs[FROGMAN][5][0]; // -.25
	entity->focaly = limbs[FROGMAN][5][1]; // 0
	entity->focalz = limbs[FROGMAN][5][2]; // 3
	entity->behavior = &actFrogmanLimb;
	entity->parent = my->getUID();
	node = list_AddNodeLast(&my->children);
	node->element = entity;
	node->deconstructor = &emptyDeconstructor;
	node->size = sizeof(Entity*);
	my->bodyparts.push_back(entity);
}

void actFrogmanLimb(Entity* my)
{
	my->actMonsterLimb();
}

void frogmanDie(Entity* my)
{
	int c;
	for (c = 0; c < 5; c++)
	{
		Entity* gib = spawnGib(my);
		serverSpawnGibForClient(gib);
	}

	my->spawnBlood();

	playSoundEntity(my, 80, 128);

	my->removeMonsterDeathNodes();

	list_RemoveNode(my->mynode);
	return;
}

#define FROGMANWALKSPEED .08

void frogmanMoveBodyparts(Entity* my, Stat* myStats, double dist)
{
	node_t* node;
	Entity* entity = nullptr;
	Entity* rightbody = nullptr;
	int bodypart;

	// set invisibility //TODO: isInvisible()?
	if (multiplayer != CLIENT)
	{
		if (myStats->EFFECTS[EFF_INVISIBLE] == true)
		{
			my->flags[INVISIBLE] = true;
			my->flags[BLOCKSIGHT] = false;
			bodypart = 0;
			for (node = my->children.first; node != nullptr; node = node->next)
			{
				if (bodypart < 2)
				{
					bodypart++;
					continue;
				}
				if (bodypart >= 7)
				{
					break;
				}
				entity = (Entity*)node->element;
				if (!entity->flags[INVISIBLE])
				{
					entity->flags[INVISIBLE] = true;
					serverUpdateEntityBodypart(my, bodypart);
				}
				bodypart++;
			}
		}
		else
		{
			my->flags[INVISIBLE] = false;
			my->flags[BLOCKSIGHT] = true;
			bodypart = 0;
			for (node = my->children.first; node != NULL; node = node->next)
			{
				if (bodypart < 2)
				{
					bodypart++;
					continue;
				}
				if (bodypart >= 7)
				{
					break;
				}
				entity = (Entity*)node->element;
				if (entity->flags[INVISIBLE])
				{
					entity->flags[INVISIBLE] = false;
					serverUpdateEntityBodypart(my, bodypart);
					serverUpdateEntityFlag(my, INVISIBLE);
				}
				bodypart++;
			}
		}

		// sleeping
		if (myStats->EFFECTS[EFF_ASLEEP])
		{
			my->z = 1.5;
		}
		else
		{
			my->z = -1.5;
		}
	}

	//Move bodyparts
	for (bodypart = 0, node = my->children.first; node != NULL; node = node->next, bodypart++)
	{
		if (bodypart < 2)
		{
			continue;
		}
		entity = (Entity*)node->element;
		entity->x = my->x;
		entity->y = my->y;
		entity->z = my->z;
		entity->yaw = my->yaw;
		if (bodypart == LIMB_HUMANOID_RIGHTLEG || bodypart == LIMB_HUMANOID_LEFTARM)
		{
			if (bodypart == LIMB_HUMANOID_RIGHTLEG)
			{
				rightbody = (Entity*)node->next->element;
			}
			if (bodypart == LIMB_HUMANOID_RIGHTLEG || my->monsterAttack == 0)
			{
				// swing right leg, left arm in sync.
				if (dist > 0.1)
				{
					if (!rightbody->skill[0])
					{
						entity->pitch -= dist * FROGMANWALKSPEED;
						if (entity->pitch < -PI / 4.0)
						{
							entity->pitch = -PI / 4.0;
							if (bodypart == 3 && entity->skill[0] == 0)
							{
								playSoundEntityLocal(my, 115, 128);
								entity->skill[0] = 1;
							}
						}
					}
					else
					{
						entity->pitch += dist * FROGMANWALKSPEED;
						if (entity->pitch > PI / 4.0)
						{
							entity->pitch = PI / 4.0;
							if (bodypart == 3 && entity->skill[0] == 0)
							{
								playSoundEntityLocal(my, 115, 128);
								entity->skill[0] = 0;
							}
						}
					}
				}
				else
				{
					// if not moving, reset position of the leg/arm.
					if (entity->pitch < 0)
					{
						entity->pitch += 1 / fmax(dist * .1, 10.0);
						if (entity->pitch > 0)
						{
							entity->pitch = 0;
						}
					}
					else if (entity->pitch > 0)
					{
						entity->pitch -= 1 / fmax(dist * .1, 10.0);
						if (entity->pitch < 0)
						{
							entity->pitch = 0;
						}
					}
				}
			}
			else
			{
				// vertical chop windup
				if (my->monsterAttack == MONSTER_POSE_MELEE_WINDUP1)
				{
					if (my->monsterAttackTime == 0)
					{
						// init rotations
						entity->pitch = 0;
						my->monsterArmbended = 0;
						my->monsterWeaponYaw = 0;
						entity->roll = 0;
						entity->skill[1] = 0;
					}

					limbAnimateToLimit(entity, ANIMATE_PITCH, -0.25, 5 * PI / 4, false, 0.0);

					if (my->monsterAttackTime >= ANIMATE_DURATION_WINDUP / (monsterGlobalAnimationMultiplier / 10.0))
					{
						if (multiplayer != CLIENT)
						{
							my->attack(1, 0, nullptr);
						}
					}
				}
				// vertical chop attack
				else if (my->monsterAttack == 1)
				{
					if (entity->pitch >= 3 * PI / 2)
					{
						my->monsterArmbended = 1;
					}

					if (entity->skill[1] == 0)
					{
						// chop forwards
						if (limbAnimateToLimit(entity, ANIMATE_PITCH, 0.4, PI / 3, false, 0.0))
						{
							entity->skill[1] = 1;
						}
					}
					else if (entity->skill[1] == 1)
					{
						// return to neutral
						if (limbAnimateToLimit(entity, ANIMATE_PITCH, -0.25, 7 * PI / 4, false, 0.0))
						{
							entity->skill[0] = rightbody->skill[0];
							my->monsterWeaponYaw = 0;
							entity->pitch = rightbody->pitch;
							entity->roll = 0;
							my->monsterArmbended = 0;
							my->monsterAttack = 0;
						}
					}
				}
			}
		}
		else if (bodypart == LIMB_HUMANOID_LEFTLEG || bodypart == LIMB_HUMANOID_RIGHTARM)
		{
			if (bodypart == LIMB_HUMANOID_RIGHTARM)
			{
				if (my->monsterAttack > 0)
				{
					// vertical chop
					// get leftarm from bodypart 6 element if ready to attack
					Entity* leftarm = (Entity*)node->next->element;

					if (my->monsterAttack == 1 || my->monsterAttack == MONSTER_POSE_MELEE_WINDUP1)
					{
						if (leftarm != nullptr)
						{
							// follow the right arm animation.
							entity->pitch = leftarm->pitch;
							entity->roll = -leftarm->roll;
						}
					}
				}
				else
				{
					entity->skill[0] = rightbody->skill[0];
					entity->pitch = rightbody->pitch;
					entity->roll = 0;
				}
			}

			if (bodypart != LIMB_HUMANOID_RIGHTARM || (my->monsterAttack == 0))
			{
				// swing right arm/ left leg in sync
				if (dist > 0.1)
				{
					if (entity->skill[0])
					{
						entity->pitch -= dist * FROGMANWALKSPEED;
						if (entity->pitch < -PI / 8.0)
						{
							entity->skill[0] = 0;
							entity->pitch = -PI / 8.0;
						}
					}
					else
					{
						entity->pitch += dist * FROGMANWALKSPEED;
						if (entity->pitch > PI / 8.0)
						{
							entity->skill[0] = 1;
							entity->pitch = PI / 8.0;
						}
					}
				}
				else
				{
					// if not moving, reset position of the leg/arm.
					if (entity->pitch < 0)
					{
						entity->pitch += 1 / fmax(dist * .1, 10.0);
						if (entity->pitch > 0)
						{
							entity->pitch = 0;
						}
					}
					else if (entity->pitch > 0)
					{
						entity->pitch -= 1 / fmax(dist * .1, 10.0);
						if (entity->pitch < 0)
						{
							entity->pitch = 0;
						}
					}
				}
			}
		}
		switch (bodypart)
		{
			// torso
		case 2:
			entity->x -= .5 * cos(my->yaw);
			entity->y -= .5 * sin(my->yaw);
			entity->z += 2.25;
			break;
			// right leg
		case 3:
			entity->x += 2 * cos(my->yaw + PI / 2) - 1.25 * cos(my->yaw);
			entity->y += 2 * sin(my->yaw + PI / 2) - 1.25 * sin(my->yaw);
			entity->z += 5;
			if (my->z >= 1.4 && my->z <= 1.6)
			{
				entity->yaw += PI / 8;
				entity->pitch = -PI / 2;
			}
			else if (entity->pitch <= -PI / 3)
			{
				entity->pitch = 0;
			}
			break;
			// left leg
		case 4:
			entity->x -= 2 * cos(my->yaw + PI / 2) + 1.25 * cos(my->yaw);
			entity->y -= 2 * sin(my->yaw + PI / 2) + 1.25 * sin(my->yaw);
			entity->z += 5;
			if (my->z >= 1.4 && my->z <= 1.6)
			{
				entity->yaw -= PI / 8;
				entity->pitch = -PI / 2;
			}
			else if (entity->pitch <= -PI / 3)
			{
				entity->pitch = 0;
			}
			break;
			// right arm
		case 5:
			entity->x += 3.5 * cos(my->yaw + PI / 2) - 1 * cos(my->yaw);
			entity->y += 3.5 * sin(my->yaw + PI / 2) - 1 * sin(my->yaw);
			entity->z += .1;
			entity->yaw += MONSTER_WEAPONYAW;
			if (my->z >= 1.4 && my->z <= 1.6)
			{
				entity->pitch = 0;
			}
			break;
			// left arm
		case 6:
			entity->x -= 3.5 * cos(my->yaw + PI / 2) + 1 * cos(my->yaw);
			entity->y -= 3.5 * sin(my->yaw + PI / 2) + 1 * sin(my->yaw);
			entity->z += .1;
			if (my->z >= 1.4 && my->z <= 1.6)
			{
				entity->pitch = 0;
			}
			break;
		}
	}
	if (MONSTER_ATTACK > 0 && MONSTER_ATTACK <= MONSTER_POSE_MAGIC_CAST3)
	{
		MONSTER_ATTACKTIME++;
	}
	else if (MONSTER_ATTACK == 0)
	{
		MONSTER_ATTACKTIME = 0;
	}
	else
	{
		// do nothing, don't reset attacktime or increment it.
	}
}

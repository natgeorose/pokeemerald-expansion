SundaraVillage_Gym_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, SundaraVillage_Gym_OnLoad
	.byte 0

SundaraVillage_Gym_OnLoad:
	call_if_set FLAG_SUNDARA_FIRE_1, SundaraVillage_Gym_EventScript_Fire1
	call_if_set FLAG_SUNDARA_FIRE_2, SundaraVillage_Gym_EventScript_Fire2
	call_if_set FLAG_SUNDARA_FIRE_3, SundaraVillage_Gym_EventScript_Fire3
	call_if_set FLAG_SUNDARA_FIRE_4, SundaraVillage_Gym_EventScript_Fire4
	call_if_set FLAG_SUNDARA_FIRE_5, SundaraVillage_Gym_EventScript_Fire5
	end

SundaraVillage_Gym_EventScript_Fire1::
	setmetatile 11, 35, METATILE_Sundara_FireOut, FALSE
	return

SundaraVillage_Gym_EventScript_Fire2::
	setmetatile 6, 25, METATILE_Sundara_FireOut, FALSE
	return

SundaraVillage_Gym_EventScript_Fire3::
	setmetatile 15, 26, METATILE_Sundara_FireOut, FALSE
	return

SundaraVillage_Gym_EventScript_Fire4::
	setmetatile 9, 15, METATILE_Sundara_FireOut, FALSE
	return

SundaraVillage_Gym_EventScript_Fire5::
	setmetatile 10, 17, METATILE_Sundara_FireOut, FALSE
	return

Speaker_Flint:
    .string "Flint$"

SundaraVillage_Gym_EventScript_Flint::
	lockall
	trainerbattle_single TRAINER_FLINT, SundaraVillage_Gym_Text_FlintIntro, SundaraVillage_Gym_Text_FlintDefeat
	goto_if_unset FLAG_SUNDARA_FIRE_1, SundaraVillage_Gym_EventScript_FlintFire
	setspeaker Speaker_Flint
	msgbox SundaraVillage_Gym_Text_FlintPostBattle, MSGBOX_NPC
	end

SundaraVillage_Gym_EventScript_FlintFire::
	setspeaker Speaker_Flint
	msgbox SundaraVillage_Gym_Text_FireOut, MSGBOX_NPC
	fadescreenspeed FADE_TO_BLACK, 2
	setmetatile 11, 35, METATILE_Sundara_FireOut, FALSE
	special DrawWholeMapView
	playse SE_REPEL
	waitse
	delay 6
	fadescreenspeed FADE_FROM_BLACK, 2
	setflag FLAG_SUNDARA_FIRE_1
	releaseall
	end

SundaraVillage_Gym_Text_FireOut:
	.string "Oh I can put my campfire out!$"

SundaraVillage_Gym_Text_FlintIntro:
	.string "Magnus has been teaching me about\n"
	.string "how to start fires! Let me show you!$"

SundaraVillage_Gym_Text_FlintDefeat:
	.string "I can put out fires too!$"

SundaraVillage_Gym_Text_FlintPostBattle:
	.string "I'm learning so much from Magnus!\n"
	.string "Look at how good I am at putting\l"
	.string "fires out!$"

Speaker_Rocky:
    .string "Rocky$"

SundaraVillage_Gym_EventScript_Rocky::
	lockall
	trainerbattle_single TRAINER_ROCKY, SundaraVillage_Gym_Text_RockyIntro, SundaraVillage_Gym_Text_RockyDefeat
	goto_if_unset FLAG_SUNDARA_FIRE_2, SundaraVillage_Gym_EventScript_RockyFire
	setspeaker Speaker_Rocky
	msgbox SundaraVillage_Gym_Text_RockyPostBattle, MSGBOX_NPC
	end

SundaraVillage_Gym_EventScript_RockyFire::
	setspeaker Speaker_Rocky
	msgbox SundaraVillage_Gym_Text_FireOut, MSGBOX_NPC
	fadescreenspeed FADE_TO_BLACK, 2
	setmetatile 6, 25, METATILE_Sundara_FireOut, FALSE
	special DrawWholeMapView
	playse SE_REPEL
	waitse
	delay 6
	fadescreenspeed FADE_FROM_BLACK, 2
	setflag FLAG_SUNDARA_FIRE_2
	releaseall
	end

SundaraVillage_Gym_Text_RockyIntro:
	.string "Be careful!\n"
	.string "Don't stand too close to the fire!$"

SundaraVillage_Gym_Text_RockyDefeat:
	.string "Too hot!$"

SundaraVillage_Gym_Text_RockyPostBattle:
	.string "It seems like you have a good handle\n"
	.string "on the do's and don'ts of fires!$"

Speaker_Carol:
    .string "Carol$"

SundaraVillage_Gym_EventScript_Carol::
	lockall
	trainerbattle_single TRAINER_CAROL, SundaraVillage_Gym_Text_CarolIntro, SundaraVillage_Gym_Text_CarolDefeat
	goto_if_unset FLAG_SUNDARA_FIRE_3, SundaraVillage_Gym_EventScript_CarolFire
	setspeaker Speaker_Carol
	msgbox SundaraVillage_Gym_Text_CarolPostBattle, MSGBOX_NPC
	end

SundaraVillage_Gym_EventScript_CarolFire::
	setspeaker Speaker_Carol
	msgbox SundaraVillage_Gym_Text_FireOut, MSGBOX_NPC
	fadescreenspeed FADE_TO_BLACK, 2
	setmetatile 15, 26, METATILE_Sundara_FireOut, FALSE
	special DrawWholeMapView
	playse SE_REPEL
	waitse
	delay 6
	fadescreenspeed FADE_FROM_BLACK, 2
	setflag FLAG_SUNDARA_FIRE_3
	releaseall
	end

SundaraVillage_Gym_Text_CarolIntro:
	.string "Magnus is teaching all of us how to\n"
	.string "start a campfire! Look at mine!$"

SundaraVillage_Gym_Text_CarolDefeat:
	.string "You beat me!$"

SundaraVillage_Gym_Text_CarolPostBattle:
	.string "We're also learning how to put\n"
	.string "fires out as well!$"

Speaker_Ashley:
    .string "Ashley$"

SundaraVillage_Gym_EventScript_Ashley::
	lockall
	trainerbattle_single TRAINER_ASHLEY, SundaraVillage_Gym_Text_AshleyIntro, SundaraVillage_Gym_Text_AshleyDefeat
	goto_if_unset FLAG_SUNDARA_FIRE_4, SundaraVillage_Gym_EventScript_AshleyFire
	setspeaker Speaker_Ashley
	msgbox SundaraVillage_Gym_Text_AshleyPostBattle, MSGBOX_NPC
	end

SundaraVillage_Gym_EventScript_AshleyFire::
	setspeaker Speaker_Ashley
	msgbox SundaraVillage_Gym_Text_FireOut, MSGBOX_NPC
	fadescreenspeed FADE_TO_BLACK, 2
	setmetatile 9, 15, METATILE_Sundara_FireOut, FALSE
	special DrawWholeMapView
	playse SE_REPEL
	waitse
	delay 6
	fadescreenspeed FADE_FROM_BLACK, 2
	setflag FLAG_SUNDARA_FIRE_4
	releaseall
	end

SundaraVillage_Gym_Text_AshleyIntro:
	.string "You'll have to get through me to get\n"
	.string "to Magnus! I'm not going down easily!$"

SundaraVillage_Gym_Text_AshleyDefeat:
	.string "Woah you are good!$"

SundaraVillage_Gym_Text_AshleyPostBattle:
	.string "I'm strong, but I'm nowhere close\n"
	.string "to Magnus. He's a great mentor, and\l"
	.string "an even better Leader!$"

Speaker_Justin:
    .string "Justin$"

SundaraVillage_Gym_EventScript_Justin::
	lockall
	trainerbattle_single TRAINER_JUSTIN, SundaraVillage_Gym_Text_JustinIntro, SundaraVillage_Gym_Text_JustinDefeat
	goto_if_unset FLAG_SUNDARA_FIRE_5, SundaraVillage_Gym_EventScript_JustinFire
	setspeaker Speaker_Justin
	msgbox SundaraVillage_Gym_Text_JustinPostBattle, MSGBOX_NPC
	end

SundaraVillage_Gym_EventScript_JustinFire::
	setspeaker Speaker_Justin
	msgbox SundaraVillage_Gym_Text_FireOut, MSGBOX_NPC
	fadescreenspeed FADE_TO_BLACK, 2
	setmetatile 10, 17, METATILE_Sundara_FireOut, FALSE
	special DrawWholeMapView
	playse SE_REPEL
	waitse
	delay 6
	fadescreenspeed FADE_FROM_BLACK, 2
	setflag FLAG_SUNDARA_FIRE_5
	releaseall
	end

SundaraVillage_Gym_Text_JustinIntro:
	.string "Fire types are the best!\n"
	.string "Look at how many I have!$"

SundaraVillage_Gym_Text_JustinDefeat:
	.string "Nooo!$"

SundaraVillage_Gym_Text_JustinPostBattle:
	.string "Whose campfire is that?\n"
	.string "No idea, but it's not mine!$"

SundaraVillage_Gym_EventScript_Jim::
	lockall
	faceplayer
	goto_if_set FLAG_DEFEATED_SUNDARA_GYM, SundaraVillage_Gym_EventScript_JimPostVictory
	setspeaker Speaker_Jim
	msgbox SundaraVillage_Gym_Text_JimAdvice, MSGBOX_NPC
	closemessage
	releaseall
	end

SundaraVillage_Gym_EventScript_JimPostVictory::
	setspeaker Speaker_Jim
	msgbox SundaraVillage_Gym_Text_JimPostVictory, MSGBOX_NPC
	closemessage
	releaseall
	end

SundaraVillage_Gym_Text_JimAdvice:
	.string "Hey challenger! The Leader of Sundara\n"
	.string "Village Gym, Magnus, is a Fire type\l"
	.string "enthusiast.\p"
	.string "Rock, Ground, and Water type Pokémon\n"
	.string "can give you the edge in this battle.\l"
	.string "Good luck!$"

SundaraVillage_Gym_Text_JimPostVictory:
	.string "You've got two badges now, you're on\n"
	.string "a hot streak!$"

Speaker_Magnus:
	.string "Magnus$"

SundaraVillage_Gym_EventScript_Magnus::
	lockall
	trainerbattle_single TRAINER_MAGNUS, SundaraVillage_Gym_Text_MagnusIntro, SundaraVillage_Gym_Text_MagnusDefeat, SundaraVillage_Gym_EventScript_MagnusDefeated, NO_MUSIC
	goto_if_unset FLAG_RECEIVED_TM_WILL_O_WISP, SundaraVillage_Gym_EventScript_GiveWillOWisp
	setspeaker Speaker_Magnus
	msgbox SundaraVillage_Gym_Text_MagnusPostBattle, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

SundaraVillage_Gym_EventScript_MagnusDefeated::
	lockall
	closemessage
	msgbox SundaraVillage_Gym_Text_ReceivedCampfireBadge, MSGBOX_DEFAULT
	closemessage
	call Common_EventScript_PlayGymBadgeFanfare
	setspeaker Speaker_Magnus
	msgbox SundaraVillage_Gym_Text_CampfireBadgeInfoTakeThis, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_DEFEATED_SUNDARA_GYM
	setflag FLAG_BADGE02_GET
	setvar VAR_LEVEL_CAP, 29
	setvar VAR_0x8008, 2
	call Common_EventScript_SetGymTrainers
	goto SundaraVillage_Gym_EventScript_GiveWillOWisp
	end

SundaraVillage_Gym_EventScript_GiveWillOWisp::
	giveitem ITEM_TM_WILL_O_WISP
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM_WILL_O_WISP
	setspeaker Speaker_Magnus
	msgbox SundaraVillage_Gym_Text_ExplainWillOWisp, MSGBOX_DEFAULT
	closemessage
	goto SundaraVillage_Gym_EventScript_NewTrouble
	end

SundaraVillage_Gym_EventScript_NewTrouble::
	lockall
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	playse SE_PIN
	applymovement LOCALID_PLAYER, Common_Movement_ExclamationMark
	applymovement LOCALID_MAGNUS, Common_Movement_ExclamationMark
	waitmovement 0
	setspeaker Speaker_Magnus
	msgbox SundaraVillage_Gym_Text_WhatWasThat, MSGBOX_DEFAULT
	closemessage
	clearflag FLAG_HIDE_SUNDARA_JIM
	addobject LOCALID_SUNDARA_JIM
	special SpawnCameraObject
	applymovement LOCALID_CAMERA, Common_Movement_WalkDown2
	applymovement LOCALID_PLAYER, Common_Movement_FaceDown
	applymovement LOCALID_SUNDARA_JIM, SundaraVillage_Gym_Movement_JimEnter
	waitmovement 0
	setspeaker Speaker_Jim
	msgbox SundaraVillage_Gym_Text_JimTrouble, MSGBOX_DEFAULT
	closemessage
	playse SE_PIN
	applymovement LOCALID_MAGNUS, Common_Movement_ExclamationMark
	waitmovement 0
	setspeaker Speaker_Magnus
	msgbox SundaraVillage_Gym_Text_MagnusOhNo, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	setspeaker Speaker_Magnus
	msgbox SundaraVillage_Gym_Text_MagnusPlayer, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, Common_Movement_WalkRightFast
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_FaceDown
	applymovement LOCALID_MAGNUS, SundaraVillage_Gym_Movement_MagnusExit
	delay 30
	applymovement LOCALID_SUNDARA_JIM, SundaraVillage_Gym_Movement_JimExit
	waitmovement 0
	applymovement LOCALID_CAMERA, Common_Movement_WalkUp2
	waitmovement 0
	applymovement LOCALID_CAMERA, Common_Movement_WalkRight
	waitmovement 0
	special RemoveCameraObject
	removeobject LOCALID_MAGNUS
	removeobject LOCALID_SUNDARA_JIM
	setflag FLAG_HIDE_SUNDARA_JIM
	setflag FLAG_MAGNUS_GYM
	clearflag FLAG_MAGNUS_OUTSIDE
	setvar VAR_STORY, 18
	releaseall
	end

SundaraVillage_Gym_Text_MagnusIntro:
	.string "Hello there! I'm Magnus, the Gym Leader\n"
	.string "of Sundara Village.\p"
	.string "As the former head of the Serenado\n"
	.string "Pokémon Rangers, I've dedicated my life\l"
	.string "to taking care of Fire type Pokémon.\p"
	.string "Fire type Pokémon, like fire itself,\n"
	.string "are incredibly volatile. They can be a\l"
	.string "great asset, or extremely dangerous.\p"
	.string "That's why even as a Gym Leader, I still\n"
	.string "want to teach others how to properly\l"
	.string "deal with fire, and Fire type Pokémon.\p"
	.string "Let's see if you can handle the heat!$"

SundaraVillage_Gym_Text_MagnusDefeat:
	.string "Now that's how you deal with fire!\n"
	.string "Very well done!\p"
	.string "Please accept the official Pokémon\n"
	.string "League Campfire Badge.$"

SundaraVillage_Gym_Text_ReceivedCampfireBadge:
	.string "{PLAYER} received the Campfire Badge\n"
	.string "from Magnus.$"

SundaraVillage_Gym_Text_CampfireBadgeInfoTakeThis:
	.string "As proof of your victory, here is\n"
	.string "the Campfire Badge!\p"
	.string "And please take this with you.$"

SundaraVillage_Gym_Text_ExplainWillOWisp:
	.string "TM20 contains the move Will-O-Wisp.\p"
	.string "It inflicts your opponent with a\n"
	.string "nasty burn, dealing damage over time\l"
	.string "and cutting their Attack in half.$"

SundaraVillage_Gym_Text_MagnusPostBattle:
	.string "As much as I love being a Gym Leader,\n"
	.string "I do miss leading the Rangers.$"

SundaraVillage_Gym_Text_WhatWasThat:
	.string "What was that??$"

SundaraVillage_Gym_Movement_JimEnter:
    walk_fast_up
    walk_fast_up
    walk_fast_up
    walk_fast_up
    step_end

SundaraVillage_Gym_Text_JimTrouble:
	.string "Magnus, there appears to be something\n"
	.string "going on in Coalscorch Quarry!$"

SundaraVillage_Gym_Text_MagnusOhNo:
	.string "Oh no! The miners in the quarry could\n"
	.string "be in danger! We have to move now!$"

SundaraVillage_Gym_Text_MagnusPlayer:
	.string "I'm sorry to ask something of you,\n"
	.string "but you are a capable trainer and\l"
	.string "this is urgent!\p"
	.string "Please meet me in Coalscorch Quarry,\n"
	.string "hopefully we can figure out what is\l"
	.string "going on!$"

SundaraVillage_Gym_Movement_MagnusExit:
    walk_fast_down
    walk_fast_down
    walk_fast_down
    walk_fast_left
    walk_fast_down
    walk_fast_down
    walk_fast_down
    walk_fast_down
    walk_fast_down
    walk_fast_down
    step_end

SundaraVillage_Gym_Movement_JimExit:
    walk_fast_down
    walk_fast_down
    walk_fast_down
    walk_fast_down
    walk_fast_down
    step_end





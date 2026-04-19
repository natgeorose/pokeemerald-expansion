FellhavenTown_Tutor_MapScripts::
	.byte 0

Speaker_MoveTutor:
    .string "Move Tutor$"

FellhavenTown_Tutor_EventScript_Tutor::
	lockall
	goto_if_set FLAG_MET_FELLHAVEN_TUTOR, FellhavenTown_Tutor_EventScript_TutorPost
	setspeaker Speaker_MoveTutor
	msgbox FellhavenTown_Tutor_Text_TutorIntro, MSGBOX_NPC
	closemessage
	setflag FLAG_MET_FELLHAVEN_TUTOR
	goto FellhavenTown_Tutor_EventScript_TutorPost
	releaseall
	end

FellhavenTown_Tutor_EventScript_TutorPost::
	checkitem ITEM_HEART_SCALE
	goto_if_eq VAR_RESULT, FALSE, FellhavenTown_Tutor_EventScript_NoHeartScale
	setspeaker Speaker_MoveTutor
	msgbox FellhavenTown_Tutor_Text_YesHeartScale, MSGBOX_NPC
	closemessage
	goto FellhavenTown_Tutor_EventScript_BadgeTutor
	releaseall 
	end

FellhavenTown_Tutor_EventScript_NoHeartScale::
	setspeaker Speaker_MoveTutor
	msgbox FellhavenTown_Tutor_Text_NoHeartScale, MSGBOX_NPC
	closemessage
	releaseall
	end

FellhavenTown_Tutor_Text_TutorIntro:
	.string "Well hello there young Trainer!\p"
	.string "I am the Move Tutor, I help Trainers\n"
	.string "out by teaching their Pokémon\l"
	.string "powerful new moves.\p"
	.string "I can teach your Pokémon different\n"
	.string "moves based on the number of Gym\l"
	.string "badges that you have obtained.\p"
	.string "Oh ho I don't work for free though!\n"
	.string "I am a Heart Scale aficionado,\p"
	.string "bring me one and I will happily teach\n"
	.string "your Pokémon a move.$"

FellhavenTown_Tutor_Text_NoHeartScale:
	.string "Hmm you don't seem to have a Heart\n"
	.string "Scale, come back when you do!$"

FellhavenTown_Tutor_Text_YesHeartScale:
	.string "Oh that's a Heart Scale!\n"
	.string "What move do you want to learn?$"

MoveTutor_EventScript_OpenPartyMenuNew:
	special ChooseMonForMoveTutor
	waitstate
	goto_if_eq VAR_RESULT, 0, MoveTutor_EventScript_Exit
	closemessage
	msgbox FellhavenTown_MoveTutor_Text_HandedOverHeartScale, MSGBOX_DEFAULT
	closemessage
	removeitem ITEM_HEART_SCALE
	goto MoveTutor_EventScript_Exit
	return

MoveTutor_EventScript_Exit::
	closemessage
	release
	end

FellhavenTown_MoveTutor_Text_HandedOverHeartScale:
	.string "{PLAYER} handed over a Heart Scale\n"
	.string "to the Move Tutor.$"

FellhavenTown_Tutor_EventScript_BadgeTutor::
	lockall
	goto_if_set FLAG_BADGE08_GET, FellhavenTown_Tutor_EventScript_BadgeTutor_StackFate
	goto_if_set FLAG_BADGE07_GET, FellhavenTown_Tutor_EventScript_BadgeTutor_StackTundra
	goto_if_set FLAG_BADGE06_GET, FellhavenTown_Tutor_EventScript_BadgeTutor_StackVenom
	goto_if_set FLAG_BADGE05_GET, FellhavenTown_Tutor_EventScript_BadgeTutor_StackGambit
	goto_if_set FLAG_BADGE04_GET, FellhavenTown_Tutor_EventScript_BadgeTutor_StackCircuit
	goto_if_set FLAG_BADGE03_GET, FellhavenTown_Tutor_EventScript_BadgeTutor_StackZodiac
	goto_if_set FLAG_BADGE02_GET, FellhavenTown_Tutor_EventScript_BadgeTutor_StackCampfire
	goto_if_set FLAG_BADGE01_GET, FellhavenTown_Tutor_EventScript_BadgeTutor_StackInk
	releaseall
	end

FellhavenTown_Tutor_EventScript_BadgeTutor_StackInk:
	dynmultipush FellhavenTown_Tutor_EventScript_BadgeTutor_Text_InkBadge, 0
	dynmultistack 0, 0, FALSE, 8, FALSE, 0, DYN_MULTICHOICE_CB_NONE
	switch VAR_RESULT
	case 0, MoveTutor_EventScript_InkBadge
	case MULTI_B_PRESSED, MoveTutor_EventScript_Exit
	end

FellhavenTown_Tutor_EventScript_BadgeTutor_StackCampfire:
	dynmultipush FellhavenTown_Tutor_EventScript_BadgeTutor_Text_InkBadge, 0
	dynmultipush FellhavenTown_Tutor_EventScript_BadgeTutor_Text_CampfireBadge, 1
	dynmultistack 0, 0, FALSE, 8, FALSE, 0, DYN_MULTICHOICE_CB_NONE
	switch VAR_RESULT
	case 0, MoveTutor_EventScript_InkBadge
	case 1, MoveTutor_EventScript_CampfireBadge
	case MULTI_B_PRESSED, MoveTutor_EventScript_Exit
	end

FellhavenTown_Tutor_EventScript_BadgeTutor_StackZodiac:
	dynmultipush FellhavenTown_Tutor_EventScript_BadgeTutor_Text_InkBadge, 0
	dynmultipush FellhavenTown_Tutor_EventScript_BadgeTutor_Text_CampfireBadge, 1
	dynmultipush FellhavenTown_Tutor_EventScript_BadgeTutor_Text_ZodiacBadge, 2
	dynmultistack 0, 0, FALSE, 8, FALSE, 0, DYN_MULTICHOICE_CB_NONE
	switch VAR_RESULT
	case 0, MoveTutor_EventScript_InkBadge
	case 1, MoveTutor_EventScript_CampfireBadge
	case 2, MoveTutor_EventScript_ZodiacBadge
	case MULTI_B_PRESSED, MoveTutor_EventScript_Exit
	end

FellhavenTown_Tutor_EventScript_BadgeTutor_StackCircuit:
	dynmultipush FellhavenTown_Tutor_EventScript_BadgeTutor_Text_InkBadge, 0
	dynmultipush FellhavenTown_Tutor_EventScript_BadgeTutor_Text_CampfireBadge, 1
	dynmultipush FellhavenTown_Tutor_EventScript_BadgeTutor_Text_ZodiacBadge, 2
	dynmultipush FellhavenTown_Tutor_EventScript_BadgeTutor_Text_CircuitBadge, 3
	dynmultistack 0, 0, FALSE, 8, FALSE, 0, DYN_MULTICHOICE_CB_NONE
	switch VAR_RESULT
	case 0, MoveTutor_EventScript_InkBadge
	case 1, MoveTutor_EventScript_CampfireBadge
	case 2, MoveTutor_EventScript_ZodiacBadge
	case 3, MoveTutor_EventScript_CircuitBadge
	case MULTI_B_PRESSED, MoveTutor_EventScript_Exit
	end

FellhavenTown_Tutor_EventScript_BadgeTutor_StackGambit:
	dynmultipush FellhavenTown_Tutor_EventScript_BadgeTutor_Text_InkBadge, 0
	dynmultipush FellhavenTown_Tutor_EventScript_BadgeTutor_Text_CampfireBadge, 1
	dynmultipush FellhavenTown_Tutor_EventScript_BadgeTutor_Text_ZodiacBadge, 2
	dynmultipush FellhavenTown_Tutor_EventScript_BadgeTutor_Text_CircuitBadge, 3
	dynmultipush FellhavenTown_Tutor_EventScript_BadgeTutor_Text_GambitBadge, 4
	dynmultistack 0, 0, FALSE, 8, FALSE, 0, DYN_MULTICHOICE_CB_NONE
	switch VAR_RESULT
	case 0, MoveTutor_EventScript_InkBadge
	case 1, MoveTutor_EventScript_CampfireBadge
	case 2, MoveTutor_EventScript_ZodiacBadge
	case 3, MoveTutor_EventScript_CircuitBadge
	case 4, MoveTutor_EventScript_GambitBadge
	case MULTI_B_PRESSED, MoveTutor_EventScript_Exit
	end

FellhavenTown_Tutor_EventScript_BadgeTutor_StackVenom:
	dynmultipush FellhavenTown_Tutor_EventScript_BadgeTutor_Text_InkBadge, 0
	dynmultipush FellhavenTown_Tutor_EventScript_BadgeTutor_Text_CampfireBadge, 1
	dynmultipush FellhavenTown_Tutor_EventScript_BadgeTutor_Text_ZodiacBadge, 2
	dynmultipush FellhavenTown_Tutor_EventScript_BadgeTutor_Text_CircuitBadge, 3
	dynmultipush FellhavenTown_Tutor_EventScript_BadgeTutor_Text_GambitBadge, 4
	dynmultipush FellhavenTown_Tutor_EventScript_BadgeTutor_Text_VenomBadge, 5
	dynmultistack 0, 0, FALSE, 8, FALSE, 0, DYN_MULTICHOICE_CB_NONE
	switch VAR_RESULT
	case 0, MoveTutor_EventScript_InkBadge
	case 1, MoveTutor_EventScript_CampfireBadge
	case 2, MoveTutor_EventScript_ZodiacBadge
	case 3, MoveTutor_EventScript_CircuitBadge
	case 4, MoveTutor_EventScript_GambitBadge
	case 5, MoveTutor_EventScript_VenomBadge
	case MULTI_B_PRESSED, MoveTutor_EventScript_Exit
	end

FellhavenTown_Tutor_EventScript_BadgeTutor_StackTundra:
	dynmultipush FellhavenTown_Tutor_EventScript_BadgeTutor_Text_InkBadge, 0
	dynmultipush FellhavenTown_Tutor_EventScript_BadgeTutor_Text_CampfireBadge, 1
	dynmultipush FellhavenTown_Tutor_EventScript_BadgeTutor_Text_ZodiacBadge, 2
	dynmultipush FellhavenTown_Tutor_EventScript_BadgeTutor_Text_CircuitBadge, 3
	dynmultipush FellhavenTown_Tutor_EventScript_BadgeTutor_Text_GambitBadge, 4
	dynmultipush FellhavenTown_Tutor_EventScript_BadgeTutor_Text_VenomBadge, 5
	dynmultipush FellhavenTown_Tutor_EventScript_BadgeTutor_Text_TundraBadge, 6
	dynmultistack 0, 0, FALSE, 7, FALSE, 0, DYN_MULTICHOICE_CB_NONE
	switch VAR_RESULT
	case 0, MoveTutor_EventScript_InkBadge
	case 1, MoveTutor_EventScript_CampfireBadge
	case 2, MoveTutor_EventScript_ZodiacBadge
	case 3, MoveTutor_EventScript_CircuitBadge
	case 4, MoveTutor_EventScript_GambitBadge
	case 5, MoveTutor_EventScript_VenomBadge
	case 6, MoveTutor_EventScript_TundraBadge
	case MULTI_B_PRESSED, MoveTutor_EventScript_Exit
	end
	

FellhavenTown_Tutor_EventScript_BadgeTutor_StackFate:
	dynmultipush FellhavenTown_Tutor_EventScript_BadgeTutor_Text_InkBadge, 0
	dynmultipush FellhavenTown_Tutor_EventScript_BadgeTutor_Text_CampfireBadge, 1
	dynmultipush FellhavenTown_Tutor_EventScript_BadgeTutor_Text_ZodiacBadge, 2
	dynmultipush FellhavenTown_Tutor_EventScript_BadgeTutor_Text_CircuitBadge, 3
	dynmultipush FellhavenTown_Tutor_EventScript_BadgeTutor_Text_GambitBadge, 4
	dynmultipush FellhavenTown_Tutor_EventScript_BadgeTutor_Text_VenomBadge, 5
	dynmultipush FellhavenTown_Tutor_EventScript_BadgeTutor_Text_TundraBadge, 6
	dynmultipush FellhavenTown_Tutor_EventScript_BadgeTutor_Text_FateBadge, 7
	dynmultistack 0, 0, FALSE, 8, FALSE, 0, DYN_MULTICHOICE_CB_NONE
	switch VAR_RESULT
	case 0, MoveTutor_EventScript_InkBadge
	case 1, MoveTutor_EventScript_CampfireBadge
	case 2, MoveTutor_EventScript_ZodiacBadge
	case 3, MoveTutor_EventScript_CircuitBadge
	case 4, MoveTutor_EventScript_GambitBadge
	case 5, MoveTutor_EventScript_VenomBadge
	case 6, MoveTutor_EventScript_TundraBadge
	case 7, MoveTutor_EventScript_FateBadge
	case MULTI_B_PRESSED, MoveTutor_EventScript_Exit
	end

MoveTutor_EventScript_InkBadge::
	dynmultipush MoveTutor_EventScript_InkBadge_Text_0, 0
	dynmultipush MoveTutor_EventScript_InkBadge_Text_1, 1
	dynmultipush MoveTutor_EventScript_InkBadge_Text_2, 2
	dynmultipush MoveTutor_EventScript_InkBadge_Text_3, 3
	dynmultipush MoveTutor_EventScript_InkBadge_Text_4, 4
	dynmultipush MoveTutor_EventScript_InkBadge_Text_5, 5
	dynmultipush MoveTutor_EventScript_InkBadge_Text_6, 6
	dynmultipush MoveTutor_EventScript_InkBadge_Text_7, 7
	dynmultipush MoveTutor_EventScript_InkBadge_Text_8, 8
	dynmultipush MoveTutor_EventScript_InkBadge_Text_9, 9
	dynmultistack 0, 0, FALSE, 8, FALSE, 0, DYN_MULTICHOICE_CB_NONE
	switch VAR_RESULT
	case 0, MoveTutor_EventScript_InkBadge_2
	case 1, MoveTutor_EventScript_InkBadge_3
	case 2, MoveTutor_EventScript_InkBadge_4
	case 3, MoveTutor_EventScript_InkBadge_5
	case 4, MoveTutor_EventScript_InkBadge_6
	case 5, MoveTutor_EventScript_InkBadge_7
	case 6, MoveTutor_EventScript_InkBadge_8
	case 7, MoveTutor_EventScript_InkBadge_9
	case 8, MoveTutor_EventScript_InkBadge_10
	case 9, MoveTutor_EventScript_InkBadge_11
	case MULTI_B_PRESSED, FellhavenTown_Tutor_EventScript_BadgeTutor
	return

MoveTutor_EventScript_InkBadge_2:
	setvar VAR_0x8005, MOVE_LOW_KICK
	call MoveTutor_EventScript_OpenPartyMenuNew
	return

MoveTutor_EventScript_InkBadge_3:
	setvar VAR_0x8005, MOVE_ACID_SPRAY
	call MoveTutor_EventScript_OpenPartyMenuNew
	return

MoveTutor_EventScript_InkBadge_4:
	setvar VAR_0x8005, MOVE_STRUGGLE_BUG
	call MoveTutor_EventScript_OpenPartyMenuNew
	return

MoveTutor_EventScript_InkBadge_5:
	setvar VAR_0x8005, MOVE_NIGHT_SHADE
	call MoveTutor_EventScript_OpenPartyMenuNew
	return

MoveTutor_EventScript_InkBadge_6:
	setvar VAR_0x8005, MOVE_FLING
	call MoveTutor_EventScript_OpenPartyMenuNew
	return

MoveTutor_EventScript_InkBadge_7:
	setvar VAR_0x8005, MOVE_METAL_CLAW
	call MoveTutor_EventScript_OpenPartyMenuNew
	return

MoveTutor_EventScript_InkBadge_8:
	setvar VAR_0x8005, MOVE_HAZE
	call MoveTutor_EventScript_OpenPartyMenuNew
	return

MoveTutor_EventScript_InkBadge_9:
	setvar VAR_0x8005, MOVE_PAIN_SPLIT
	call MoveTutor_EventScript_OpenPartyMenuNew
	return

MoveTutor_EventScript_InkBadge_10:
	setvar VAR_0x8005, MOVE_BUG_BITE
	call MoveTutor_EventScript_OpenPartyMenuNew
	return

MoveTutor_EventScript_InkBadge_11:
	setvar VAR_0x8005, MOVE_HELPING_HAND
	call MoveTutor_EventScript_OpenPartyMenuNew
	return

MoveTutor_EventScript_CampfireBadge::
	dynmultipush MoveTutor_EventScript_CampfireBadge_Text_0, 0
	dynmultipush MoveTutor_EventScript_CampfireBadge_Text_1, 1
	dynmultipush MoveTutor_EventScript_CampfireBadge_Text_2, 2
	dynmultipush MoveTutor_EventScript_CampfireBadge_Text_3, 3
	dynmultipush MoveTutor_EventScript_CampfireBadge_Text_4, 4
	dynmultipush MoveTutor_EventScript_CampfireBadge_Text_5, 5
	dynmultipush MoveTutor_EventScript_CampfireBadge_Text_6, 6
	dynmultipush MoveTutor_EventScript_CampfireBadge_Text_7, 7
	dynmultipush MoveTutor_EventScript_CampfireBadge_Text_8, 8
	dynmultipush MoveTutor_EventScript_CampfireBadge_Text_9, 9
	dynmultistack 0, 0, FALSE, 8, FALSE, 0, DYN_MULTICHOICE_CB_NONE
	switch VAR_RESULT
	case 0, MoveTutor_EventScript_CampfireBadge_2
	case 1, MoveTutor_EventScript_CampfireBadge_3
	case 2, MoveTutor_EventScript_CampfireBadge_4
	case 3, MoveTutor_EventScript_CampfireBadge_5
	case 4, MoveTutor_EventScript_CampfireBadge_6
	case 5, MoveTutor_EventScript_CampfireBadge_7
	case 6, MoveTutor_EventScript_CampfireBadge_8
	case 7, MoveTutor_EventScript_CampfireBadge_9
	case 8, MoveTutor_EventScript_CampfireBadge_10
	case 9, MoveTutor_EventScript_CampfireBadge_11
	case MULTI_B_PRESSED, FellhavenTown_Tutor_EventScript_BadgeTutor
	return

MoveTutor_EventScript_CampfireBadge_2:
	setvar VAR_0x8005, MOVE_STORED_POWER
	call MoveTutor_EventScript_OpenPartyMenuNew
	return

MoveTutor_EventScript_CampfireBadge_3:
	setvar VAR_0x8005, MOVE_DRAINING_KISS
	call MoveTutor_EventScript_OpenPartyMenuNew
	return

MoveTutor_EventScript_CampfireBadge_4:
	setvar VAR_0x8005, MOVE_MUD_SHOT
	call MoveTutor_EventScript_OpenPartyMenuNew
	return

MoveTutor_EventScript_CampfireBadge_5:
	setvar VAR_0x8005, MOVE_CHILLING_WATER
	call MoveTutor_EventScript_OpenPartyMenuNew
	return

MoveTutor_EventScript_CampfireBadge_6:
	setvar VAR_0x8005, MOVE_MAGICAL_LEAF
	call MoveTutor_EventScript_OpenPartyMenuNew
	return

MoveTutor_EventScript_CampfireBadge_7:
	setvar VAR_0x8005, MOVE_BATON_PASS
	call MoveTutor_EventScript_OpenPartyMenuNew
	return

MoveTutor_EventScript_CampfireBadge_8:
	setvar VAR_0x8005, MOVE_REVERSAL
	call MoveTutor_EventScript_OpenPartyMenuNew
	return

MoveTutor_EventScript_CampfireBadge_9:
	setvar VAR_0x8005, MOVE_SUPER_FANG
	call MoveTutor_EventScript_OpenPartyMenuNew
	return

MoveTutor_EventScript_CampfireBadge_10:
	setvar VAR_0x8005, MOVE_ENDEAVOR
	call MoveTutor_EventScript_OpenPartyMenuNew
	return

MoveTutor_EventScript_CampfireBadge_11:
	setvar VAR_0x8005, MOVE_VACUUM_WAVE
	call MoveTutor_EventScript_OpenPartyMenuNew
	return

MoveTutor_EventScript_ZodiacBadge::
	dynmultipush MoveTutor_EventScript_ZodiacBadge_Text_0, 0
	dynmultipush MoveTutor_EventScript_ZodiacBadge_Text_1, 1
	dynmultipush MoveTutor_EventScript_ZodiacBadge_Text_2, 2
	dynmultipush MoveTutor_EventScript_ZodiacBadge_Text_3, 3
	dynmultipush MoveTutor_EventScript_ZodiacBadge_Text_4, 4
	dynmultipush MoveTutor_EventScript_ZodiacBadge_Text_5, 5
	dynmultipush MoveTutor_EventScript_ZodiacBadge_Text_6, 6
	dynmultipush MoveTutor_EventScript_ZodiacBadge_Text_7, 7
	dynmultipush MoveTutor_EventScript_ZodiacBadge_Text_8, 8
	dynmultipush MoveTutor_EventScript_ZodiacBadge_Text_9, 9
	dynmultistack 0, 0, FALSE, 8, FALSE, 0, DYN_MULTICHOICE_CB_NONE
	switch VAR_RESULT
	case 0, MoveTutor_EventScript_ZodiacBadge_2
	case 1, MoveTutor_EventScript_ZodiacBadge_3
	case 2, MoveTutor_EventScript_ZodiacBadge_4
	case 3, MoveTutor_EventScript_ZodiacBadge_5
	case 4, MoveTutor_EventScript_ZodiacBadge_6
	case 5, MoveTutor_EventScript_ZodiacBadge_7
	case 6, MoveTutor_EventScript_ZodiacBadge_8
	case 7, MoveTutor_EventScript_ZodiacBadge_9
	case 8, MoveTutor_EventScript_ZodiacBadge_10
	case 9, MoveTutor_EventScript_ZodiacBadge_11
	case MULTI_B_PRESSED, FellhavenTown_Tutor_EventScript_BadgeTutor
	return

MoveTutor_EventScript_ZodiacBadge_2:
	setvar VAR_0x8005, MOVE_FIRE_FANG
	call MoveTutor_EventScript_OpenPartyMenuNew
	return

MoveTutor_EventScript_ZodiacBadge_3:
	setvar VAR_0x8005, MOVE_THUNDER_FANG
	call MoveTutor_EventScript_OpenPartyMenuNew
	return

MoveTutor_EventScript_ZodiacBadge_4:
	setvar VAR_0x8005, MOVE_ICE_FANG
	call MoveTutor_EventScript_OpenPartyMenuNew
	return

MoveTutor_EventScript_ZodiacBadge_5:
	setvar VAR_0x8005, MOVE_AIR_SLASH
	call MoveTutor_EventScript_OpenPartyMenuNew
	return

MoveTutor_EventScript_ZodiacBadge_6:
	setvar VAR_0x8005, MOVE_DUAL_WINGBEAT
	call MoveTutor_EventScript_OpenPartyMenuNew
	return

MoveTutor_EventScript_ZodiacBadge_7:
	setvar VAR_0x8005, MOVE_FLIP_TURN
	call MoveTutor_EventScript_OpenPartyMenuNew
	return

MoveTutor_EventScript_ZodiacBadge_8:
	setvar VAR_0x8005, MOVE_GRASSY_GLIDE
	call MoveTutor_EventScript_OpenPartyMenuNew
	return

MoveTutor_EventScript_ZodiacBadge_9:
	setvar VAR_0x8005, MOVE_CURSE
	call MoveTutor_EventScript_OpenPartyMenuNew
	return

MoveTutor_EventScript_ZodiacBadge_10:
	setvar VAR_0x8005, MOVE_UPPER_HAND
	call MoveTutor_EventScript_OpenPartyMenuNew
	return

MoveTutor_EventScript_ZodiacBadge_11:
	setvar VAR_0x8005, MOVE_ELECTROWEB
	call MoveTutor_EventScript_OpenPartyMenuNew
	return

MoveTutor_EventScript_CircuitBadge::
	dynmultipush MoveTutor_EventScript_CircuitBadge_Text_0, 0
	dynmultipush MoveTutor_EventScript_CircuitBadge_Text_1, 1
	dynmultipush MoveTutor_EventScript_CircuitBadge_Text_2, 2
	dynmultipush MoveTutor_EventScript_CircuitBadge_Text_3, 3
	dynmultipush MoveTutor_EventScript_CircuitBadge_Text_4, 4
	dynmultipush MoveTutor_EventScript_CircuitBadge_Text_5, 5
	dynmultipush MoveTutor_EventScript_CircuitBadge_Text_6, 6
	dynmultipush MoveTutor_EventScript_CircuitBadge_Text_7, 7
	dynmultipush MoveTutor_EventScript_CircuitBadge_Text_8, 8
	dynmultipush MoveTutor_EventScript_CircuitBadge_Text_9, 9
	dynmultistack 0, 0, FALSE, 8, FALSE, 0, DYN_MULTICHOICE_CB_NONE
	switch VAR_RESULT
	case 0, MoveTutor_EventScript_CircuitBadge_2
	case 1, MoveTutor_EventScript_CircuitBadge_3
	case 2, MoveTutor_EventScript_CircuitBadge_4
	case 3, MoveTutor_EventScript_CircuitBadge_5
	case 4, MoveTutor_EventScript_CircuitBadge_6
	case 5, MoveTutor_EventScript_CircuitBadge_7
	case 6, MoveTutor_EventScript_CircuitBadge_8
	case 7, MoveTutor_EventScript_CircuitBadge_9
	case 8, MoveTutor_EventScript_CircuitBadge_10
	case 9, MoveTutor_EventScript_CircuitBadge_11
	case MULTI_B_PRESSED, FellhavenTown_Tutor_EventScript_BadgeTutor
	return

MoveTutor_EventScript_CircuitBadge_2:
	setvar VAR_0x8005, MOVE_KNOCK_OFF
	call MoveTutor_EventScript_OpenPartyMenuNew
	return

MoveTutor_EventScript_CircuitBadge_3:
	setvar VAR_0x8005, MOVE_ICY_WIND
	call MoveTutor_EventScript_OpenPartyMenuNew
	return

MoveTutor_EventScript_CircuitBadge_4:
	setvar VAR_0x8005, MOVE_SPIKES
	call MoveTutor_EventScript_OpenPartyMenuNew
	return

MoveTutor_EventScript_CircuitBadge_5:
	setvar VAR_0x8005, MOVE_TOXIC_SPIKES
	call MoveTutor_EventScript_OpenPartyMenuNew
	return

MoveTutor_EventScript_CircuitBadge_6:
	setvar VAR_0x8005, MOVE_FLY
	call MoveTutor_EventScript_OpenPartyMenuNew
	return

MoveTutor_EventScript_CircuitBadge_7:
	setvar VAR_0x8005, MOVE_STOMPING_TANTRUM
	call MoveTutor_EventScript_OpenPartyMenuNew
	return

MoveTutor_EventScript_CircuitBadge_8:
	setvar VAR_0x8005, MOVE_BURNING_JEALOUSY
	call MoveTutor_EventScript_OpenPartyMenuNew
	return

MoveTutor_EventScript_CircuitBadge_9:
	setvar VAR_0x8005, MOVE_TEMPER_FLARE
	call MoveTutor_EventScript_OpenPartyMenuNew
	return

MoveTutor_EventScript_CircuitBadge_10:
	setvar VAR_0x8005, MOVE_POLLEN_PUFF
	call MoveTutor_EventScript_OpenPartyMenuNew
	return

MoveTutor_EventScript_CircuitBadge_11:
	setvar VAR_0x8005, MOVE_ROCK_BLAST
	call MoveTutor_EventScript_OpenPartyMenuNew
	return

MoveTutor_EventScript_GambitBadge::
	dynmultipush MoveTutor_EventScript_GambitBadge_Text_0, 0
	dynmultipush MoveTutor_EventScript_GambitBadge_Text_1, 1
	dynmultipush MoveTutor_EventScript_GambitBadge_Text_2, 2
	dynmultipush MoveTutor_EventScript_GambitBadge_Text_3, 3
	dynmultipush MoveTutor_EventScript_GambitBadge_Text_4, 4
	dynmultipush MoveTutor_EventScript_GambitBadge_Text_5, 5
	dynmultipush MoveTutor_EventScript_GambitBadge_Text_6, 6
	dynmultipush MoveTutor_EventScript_GambitBadge_Text_7, 7
	dynmultipush MoveTutor_EventScript_GambitBadge_Text_8, 8
	dynmultipush MoveTutor_EventScript_GambitBadge_Text_9, 9
	dynmultistack 0, 0, FALSE, 8, FALSE, 0, DYN_MULTICHOICE_CB_NONE
	switch VAR_RESULT
	case 0, MoveTutor_EventScript_GambitBadge_2
	case 1, MoveTutor_EventScript_GambitBadge_3
	case 2, MoveTutor_EventScript_GambitBadge_4
	case 3, MoveTutor_EventScript_GambitBadge_5
	case 4, MoveTutor_EventScript_GambitBadge_6
	case 5, MoveTutor_EventScript_GambitBadge_7
	case 6, MoveTutor_EventScript_GambitBadge_8
	case 7, MoveTutor_EventScript_GambitBadge_9
	case 8, MoveTutor_EventScript_GambitBadge_10
	case 9, MoveTutor_EventScript_GambitBadge_11
	case MULTI_B_PRESSED, FellhavenTown_Tutor_EventScript_BadgeTutor
	return

MoveTutor_EventScript_GambitBadge_2:
	setvar VAR_0x8005, MOVE_BODY_SLAM
	call MoveTutor_EventScript_OpenPartyMenuNew
	return

MoveTutor_EventScript_GambitBadge_3:
	setvar VAR_0x8005, MOVE_FIRE_PUNCH
	call MoveTutor_EventScript_OpenPartyMenuNew
	return

MoveTutor_EventScript_GambitBadge_4:
	setvar VAR_0x8005, MOVE_THUNDER_PUNCH
	call MoveTutor_EventScript_OpenPartyMenuNew
	return

MoveTutor_EventScript_GambitBadge_5:
	setvar VAR_0x8005, MOVE_ICE_PUNCH
	call MoveTutor_EventScript_OpenPartyMenuNew
	return

MoveTutor_EventScript_GambitBadge_6:
	setvar VAR_0x8005, MOVE_SEED_BOMB
	call MoveTutor_EventScript_OpenPartyMenuNew
	return

MoveTutor_EventScript_GambitBadge_7:
	setvar VAR_0x8005, MOVE_WEATHER_BALL
	call MoveTutor_EventScript_OpenPartyMenuNew
	return

MoveTutor_EventScript_GambitBadge_8:
	setvar VAR_0x8005, MOVE_WILD_CHARGE
	call MoveTutor_EventScript_OpenPartyMenuNew
	return

MoveTutor_EventScript_GambitBadge_9:
	setvar VAR_0x8005, MOVE_ALLURING_VOICE
	call MoveTutor_EventScript_OpenPartyMenuNew
	return

MoveTutor_EventScript_GambitBadge_10:
	setvar VAR_0x8005, MOVE_THROAT_CHOP
	call MoveTutor_EventScript_OpenPartyMenuNew
	return

MoveTutor_EventScript_GambitBadge_11:
	setvar VAR_0x8005, MOVE_ZEN_HEADBUTT
	call MoveTutor_EventScript_OpenPartyMenuNew
	return

MoveTutor_EventScript_VenomBadge::
	dynmultipush MoveTutor_EventScript_VenomBadge_Text_0, 0
	dynmultipush MoveTutor_EventScript_VenomBadge_Text_1, 1
	dynmultipush MoveTutor_EventScript_VenomBadge_Text_2, 2
	dynmultipush MoveTutor_EventScript_VenomBadge_Text_3, 3
	dynmultipush MoveTutor_EventScript_VenomBadge_Text_4, 4
	dynmultipush MoveTutor_EventScript_VenomBadge_Text_5, 5
	dynmultipush MoveTutor_EventScript_VenomBadge_Text_6, 6
	dynmultipush MoveTutor_EventScript_VenomBadge_Text_7, 7
	dynmultipush MoveTutor_EventScript_VenomBadge_Text_8, 8
	dynmultipush MoveTutor_EventScript_VenomBadge_Text_9, 9
	dynmultistack 0, 0, FALSE, 8, FALSE, 0, DYN_MULTICHOICE_CB_NONE
	switch VAR_RESULT
	case 0, MoveTutor_EventScript_VenomBadge_2
	case 1, MoveTutor_EventScript_VenomBadge_3
	case 2, MoveTutor_EventScript_VenomBadge_4
	case 3, MoveTutor_EventScript_VenomBadge_5
	case 4, MoveTutor_EventScript_VenomBadge_6
	case 5, MoveTutor_EventScript_VenomBadge_7
	case 6, MoveTutor_EventScript_VenomBadge_8
	case 7, MoveTutor_EventScript_VenomBadge_9
	case 8, MoveTutor_EventScript_VenomBadge_10
	case 9, MoveTutor_EventScript_VenomBadge_11
	case MULTI_B_PRESSED, FellhavenTown_Tutor_EventScript_BadgeTutor
	return

MoveTutor_EventScript_VenomBadge_2:
	setvar VAR_0x8005, MOVE_SNOWSCAPE
	call MoveTutor_EventScript_OpenPartyMenuNew
	return

MoveTutor_EventScript_VenomBadge_3:
	setvar VAR_0x8005, MOVE_MUDDY_WATER
	call MoveTutor_EventScript_OpenPartyMenuNew
	return

MoveTutor_EventScript_VenomBadge_4:
	setvar VAR_0x8005, MOVE_SOLAR_BLADE
	call MoveTutor_EventScript_OpenPartyMenuNew
	return

MoveTutor_EventScript_VenomBadge_5:
	setvar VAR_0x8005, MOVE_CRUNCH
	call MoveTutor_EventScript_OpenPartyMenuNew
	return

MoveTutor_EventScript_VenomBadge_6:
	setvar VAR_0x8005, MOVE_BUG_BUZZ
	call MoveTutor_EventScript_OpenPartyMenuNew
	return

MoveTutor_EventScript_VenomBadge_7:
	setvar VAR_0x8005, MOVE_PHANTOM_FORCE
	call MoveTutor_EventScript_OpenPartyMenuNew
	return

MoveTutor_EventScript_VenomBadge_8:
	setvar VAR_0x8005, MOVE_HIGH_HORSEPOWER
	call MoveTutor_EventScript_OpenPartyMenuNew
	return

MoveTutor_EventScript_VenomBadge_9:
	setvar VAR_0x8005, MOVE_HURRICANE
	call MoveTutor_EventScript_OpenPartyMenuNew
	return

MoveTutor_EventScript_VenomBadge_10:
	setvar VAR_0x8005, MOVE_HYPER_VOICE
	call MoveTutor_EventScript_OpenPartyMenuNew
	return

MoveTutor_EventScript_VenomBadge_11:
	setvar VAR_0x8005, MOVE_LIQUIDATION
	call MoveTutor_EventScript_OpenPartyMenuNew
	return

MoveTutor_EventScript_TundraBadge::
	dynmultipush MoveTutor_EventScript_TundraBadge_Text_0, 0
	dynmultipush MoveTutor_EventScript_TundraBadge_Text_1, 1
	dynmultipush MoveTutor_EventScript_TundraBadge_Text_2, 2
	dynmultipush MoveTutor_EventScript_TundraBadge_Text_3, 3
	dynmultipush MoveTutor_EventScript_TundraBadge_Text_4, 4
	dynmultipush MoveTutor_EventScript_TundraBadge_Text_5, 5
	dynmultipush MoveTutor_EventScript_TundraBadge_Text_6, 6
	dynmultipush MoveTutor_EventScript_TundraBadge_Text_7, 7
	dynmultipush MoveTutor_EventScript_TundraBadge_Text_8, 8
	dynmultipush MoveTutor_EventScript_TundraBadge_Text_9, 9
	dynmultistack 0, 0, FALSE, 8, FALSE, 0, DYN_MULTICHOICE_CB_NONE
	switch VAR_RESULT
	case 0, MoveTutor_EventScript_TundraBadge_2
	case 1, MoveTutor_EventScript_TundraBadge_3
	case 2, MoveTutor_EventScript_TundraBadge_4
	case 3, MoveTutor_EventScript_TundraBadge_5
	case 4, MoveTutor_EventScript_TundraBadge_6
	case 5, MoveTutor_EventScript_TundraBadge_7
	case 6, MoveTutor_EventScript_TundraBadge_8
	case 7, MoveTutor_EventScript_TundraBadge_9
	case 8, MoveTutor_EventScript_TundraBadge_10
	case 9, MoveTutor_EventScript_TundraBadge_11
	case MULTI_B_PRESSED, FellhavenTown_Tutor_EventScript_BadgeTutor
	return

MoveTutor_EventScript_TundraBadge_2:
	setvar VAR_0x8005, MOVE_ICICLE_SPEAR
	call MoveTutor_EventScript_OpenPartyMenuNew
	return

MoveTutor_EventScript_TundraBadge_3:
	setvar VAR_0x8005, MOVE_HEAT_CRASH
	call MoveTutor_EventScript_OpenPartyMenuNew
	return

MoveTutor_EventScript_TundraBadge_4:
	setvar VAR_0x8005, MOVE_TRIPLE_AXEL
	call MoveTutor_EventScript_OpenPartyMenuNew
	return

MoveTutor_EventScript_TundraBadge_5:
	setvar VAR_0x8005, MOVE_PSYCHIC_FANGS
	call MoveTutor_EventScript_OpenPartyMenuNew
	return

MoveTutor_EventScript_TundraBadge_6:
	setvar VAR_0x8005, MOVE_GUNK_SHOT
	call MoveTutor_EventScript_OpenPartyMenuNew
	return

MoveTutor_EventScript_TundraBadge_7:
	setvar VAR_0x8005, MOVE_HEAVY_SLAM
	call MoveTutor_EventScript_OpenPartyMenuNew
	return

MoveTutor_EventScript_TundraBadge_8:
	setvar VAR_0x8005, MOVE_AURA_SPHERE
	call MoveTutor_EventScript_OpenPartyMenuNew
	return

MoveTutor_EventScript_TundraBadge_9:
	setvar VAR_0x8005, MOVE_HEAT_WAVE
	call MoveTutor_EventScript_OpenPartyMenuNew
	return

MoveTutor_EventScript_TundraBadge_10:
	setvar VAR_0x8005, MOVE_SURF
	call MoveTutor_EventScript_OpenPartyMenuNew
	return

MoveTutor_EventScript_TundraBadge_11:
	setvar VAR_0x8005, MOVE_BRAVE_BIRD
	call MoveTutor_EventScript_OpenPartyMenuNew
	return

MoveTutor_EventScript_FateBadge::
	dynmultipush MoveTutor_EventScript_FateBadge_Text_0, 0
	dynmultipush MoveTutor_EventScript_FateBadge_Text_1, 1
	dynmultipush MoveTutor_EventScript_FateBadge_Text_2, 2
	dynmultipush MoveTutor_EventScript_FateBadge_Text_3, 3
	dynmultipush MoveTutor_EventScript_FateBadge_Text_4, 4
	dynmultipush MoveTutor_EventScript_FateBadge_Text_5, 5
	dynmultipush MoveTutor_EventScript_FateBadge_Text_6, 6
	dynmultipush MoveTutor_EventScript_FateBadge_Text_7, 7
	dynmultipush MoveTutor_EventScript_FateBadge_Text_8, 8
	dynmultipush MoveTutor_EventScript_FateBadge_Text_9, 9
	dynmultistack 0, 0, FALSE, 8, FALSE, 0, DYN_MULTICHOICE_CB_NONE
	switch VAR_RESULT
	case 0, MoveTutor_EventScript_FateBadge_2
	case 1, MoveTutor_EventScript_FateBadge_3
	case 2, MoveTutor_EventScript_FateBadge_4
	case 3, MoveTutor_EventScript_FateBadge_5
	case 4, MoveTutor_EventScript_FateBadge_6
	case 5, MoveTutor_EventScript_FateBadge_7
	case 6, MoveTutor_EventScript_FateBadge_8
	case 7, MoveTutor_EventScript_FateBadge_9
	case 8, MoveTutor_EventScript_FateBadge_10
	case 9, MoveTutor_EventScript_FateBadge_11
	case MULTI_B_PRESSED, FellhavenTown_Tutor_EventScript_BadgeTutor
	return

MoveTutor_EventScript_FateBadge_2:
	setvar VAR_0x8005, MOVE_GRASSY_TERRAIN
	call MoveTutor_EventScript_OpenPartyMenuNew
	return

MoveTutor_EventScript_FateBadge_3:
	setvar VAR_0x8005, MOVE_PSYCHIC_TERRAIN
	call MoveTutor_EventScript_OpenPartyMenuNew
	return

MoveTutor_EventScript_FateBadge_4:
	setvar VAR_0x8005, MOVE_ELECTRIC_TERRAIN
	call MoveTutor_EventScript_OpenPartyMenuNew
	return

MoveTutor_EventScript_FateBadge_5:
	setvar VAR_0x8005, MOVE_MISTY_TERRAIN
	call MoveTutor_EventScript_OpenPartyMenuNew
	return

MoveTutor_EventScript_FateBadge_6:
	setvar VAR_0x8005, MOVE_FLARE_BLITZ
	call MoveTutor_EventScript_OpenPartyMenuNew
	return

MoveTutor_EventScript_FateBadge_7:
	setvar VAR_0x8005, MOVE_DRACO_METEOR
	call MoveTutor_EventScript_OpenPartyMenuNew
	return

MoveTutor_EventScript_FateBadge_8:
	setvar VAR_0x8005, MOVE_STEEL_BEAM
	call MoveTutor_EventScript_OpenPartyMenuNew
	return

MoveTutor_EventScript_FateBadge_9:
	setvar VAR_0x8005, MOVE_POLTERGEIST
	call MoveTutor_EventScript_OpenPartyMenuNew
	return

MoveTutor_EventScript_FateBadge_10:
	setvar VAR_0x8005, MOVE_SUPERCELL_SLAM
	call MoveTutor_EventScript_OpenPartyMenuNew
	return

MoveTutor_EventScript_FateBadge_11:
	setvar VAR_0x8005, MOVE_METEOR_BEAM
	call MoveTutor_EventScript_OpenPartyMenuNew
	return

FellhavenTown_Tutor_EventScript_BadgeTutor_Text_InkBadge:
	.string "Ink Badge$"

FellhavenTown_Tutor_EventScript_BadgeTutor_Text_CampfireBadge:
	.string "Campfire Badge$"

FellhavenTown_Tutor_EventScript_BadgeTutor_Text_ZodiacBadge:
	.string "Zodiac Badge$"

FellhavenTown_Tutor_EventScript_BadgeTutor_Text_CircuitBadge:
	.string "Circuit Badge$"

FellhavenTown_Tutor_EventScript_BadgeTutor_Text_GambitBadge:
	.string "Gambit Badge$"

FellhavenTown_Tutor_EventScript_BadgeTutor_Text_VenomBadge:
	.string "Venom Badge$"

FellhavenTown_Tutor_EventScript_BadgeTutor_Text_TundraBadge:
	.string "Tundra Badge$"

FellhavenTown_Tutor_EventScript_BadgeTutor_Text_FateBadge:
	.string "Fate Badge$"

MoveTutor_EventScript_InkBadge_Text_0:
	.string "Low Kick$"

MoveTutor_EventScript_InkBadge_Text_1:
	.string "Acid Spray$"

MoveTutor_EventScript_InkBadge_Text_2:
	.string "Struggle Bug$"

MoveTutor_EventScript_InkBadge_Text_3:
	.string "Night Shade$"

MoveTutor_EventScript_InkBadge_Text_4:
	.string "Fling$"

MoveTutor_EventScript_InkBadge_Text_5:
	.string "Metal Claw$"

MoveTutor_EventScript_InkBadge_Text_6:
	.string "Haze$"

MoveTutor_EventScript_InkBadge_Text_7:
	.string "Pain Split$"

MoveTutor_EventScript_InkBadge_Text_8:
	.string "Bug Bite$"

MoveTutor_EventScript_InkBadge_Text_9:
	.string "Helping Hand$"

MoveTutor_EventScript_CampfireBadge_Text_0:
	.string "Stored Power$"

MoveTutor_EventScript_CampfireBadge_Text_1:
	.string "Draining Kiss$"

MoveTutor_EventScript_CampfireBadge_Text_2:
	.string "Mud Shot$"

MoveTutor_EventScript_CampfireBadge_Text_3:
	.string "Chilling Water$"

MoveTutor_EventScript_CampfireBadge_Text_4:
	.string "Magical Leaf$"

MoveTutor_EventScript_CampfireBadge_Text_5:
	.string "Baton Pass$"

MoveTutor_EventScript_CampfireBadge_Text_6:
	.string "Reversal$"

MoveTutor_EventScript_CampfireBadge_Text_7:
	.string "Super Fang$"

MoveTutor_EventScript_CampfireBadge_Text_8:
	.string "Endeavor$"

MoveTutor_EventScript_CampfireBadge_Text_9:
	.string "Vacuum Wave$"

MoveTutor_EventScript_ZodiacBadge_Text_0:
	.string "Fire Fang$"

MoveTutor_EventScript_ZodiacBadge_Text_1:
	.string "Thunder Fang$"

MoveTutor_EventScript_ZodiacBadge_Text_2:
	.string "Ice Fang$"

MoveTutor_EventScript_ZodiacBadge_Text_3:
	.string "Air Slash$"

MoveTutor_EventScript_ZodiacBadge_Text_4:
	.string "Dual Wingbeat$"

MoveTutor_EventScript_ZodiacBadge_Text_5:
	.string "Flip Turn$"

MoveTutor_EventScript_ZodiacBadge_Text_6:
	.string "Grassy Glide$"

MoveTutor_EventScript_ZodiacBadge_Text_7:
	.string "Curse$"

MoveTutor_EventScript_ZodiacBadge_Text_8:
	.string "Upper Hand$"

MoveTutor_EventScript_ZodiacBadge_Text_9:
	.string "Electroweb$"

MoveTutor_EventScript_CircuitBadge_Text_0:
	.string "Knock Off$"

MoveTutor_EventScript_CircuitBadge_Text_1:
	.string "Icy Wind$"

MoveTutor_EventScript_CircuitBadge_Text_2:
	.string "Spikes$"

MoveTutor_EventScript_CircuitBadge_Text_3:
	.string "Toxic Spikes$"

MoveTutor_EventScript_CircuitBadge_Text_4:
	.string "Fly$"

MoveTutor_EventScript_CircuitBadge_Text_5:
	.string "Stomping Tantrum$"

MoveTutor_EventScript_CircuitBadge_Text_6:
	.string "Burning Jealousy$"

MoveTutor_EventScript_CircuitBadge_Text_7:
	.string "Temper Flare$"

MoveTutor_EventScript_CircuitBadge_Text_8:
	.string "Pollen Puff$"

MoveTutor_EventScript_CircuitBadge_Text_9:
	.string "Rock Blast$"

MoveTutor_EventScript_GambitBadge_Text_0:
	.string "Body Slam$"

MoveTutor_EventScript_GambitBadge_Text_1:
	.string "Fire Punch$"

MoveTutor_EventScript_GambitBadge_Text_2:
	.string "Thunder Punch$"

MoveTutor_EventScript_GambitBadge_Text_3:
	.string "Ice Punch$"

MoveTutor_EventScript_GambitBadge_Text_4:
	.string "Seed Bomb$"

MoveTutor_EventScript_GambitBadge_Text_5:
	.string "Weather Ball$"

MoveTutor_EventScript_GambitBadge_Text_6:
	.string "Wild Charge$"

MoveTutor_EventScript_GambitBadge_Text_7:
	.string "Alluring Voice$"

MoveTutor_EventScript_GambitBadge_Text_8:
	.string "Throat Chop$"

MoveTutor_EventScript_GambitBadge_Text_9:
	.string "Zen Headbutt$"

MoveTutor_EventScript_VenomBadge_Text_0:
	.string "Snowscape$"

MoveTutor_EventScript_VenomBadge_Text_1:
	.string "Muddy Water$"

MoveTutor_EventScript_VenomBadge_Text_2:
	.string "Solar Blade$"

MoveTutor_EventScript_VenomBadge_Text_3:
	.string "Crunch$"

MoveTutor_EventScript_VenomBadge_Text_4:
	.string "Bug Buzz$"

MoveTutor_EventScript_VenomBadge_Text_5:
	.string "Phantom Force$"

MoveTutor_EventScript_VenomBadge_Text_6:
	.string "High Horsepower$"

MoveTutor_EventScript_VenomBadge_Text_7:
	.string "Hurricane$"

MoveTutor_EventScript_VenomBadge_Text_8:
	.string "Hyper Voice$"

MoveTutor_EventScript_VenomBadge_Text_9:
	.string "Liquidation$"

MoveTutor_EventScript_TundraBadge_Text_0:
	.string "Icicle Spear$"

MoveTutor_EventScript_TundraBadge_Text_1:
	.string "Heat Crash$"

MoveTutor_EventScript_TundraBadge_Text_2:
	.string "Triple Axel$"

MoveTutor_EventScript_TundraBadge_Text_3:
	.string "Psychic Fangs$"

MoveTutor_EventScript_TundraBadge_Text_4:
	.string "Gunk Shot$"

MoveTutor_EventScript_TundraBadge_Text_5:
	.string "Heavy Slam$"

MoveTutor_EventScript_TundraBadge_Text_6:
	.string "Aura Sphere$"

MoveTutor_EventScript_TundraBadge_Text_7:
	.string "Heat Wave$"

MoveTutor_EventScript_TundraBadge_Text_8:
	.string "Surf$"

MoveTutor_EventScript_TundraBadge_Text_9:
	.string "Brave Bird$"

MoveTutor_EventScript_FateBadge_Text_0:
	.string "Grassy Terrain$"

MoveTutor_EventScript_FateBadge_Text_1:
	.string "Psychic Terrain$"

MoveTutor_EventScript_FateBadge_Text_2:
	.string "Electric Terrain$"

MoveTutor_EventScript_FateBadge_Text_3:
	.string "Misty Terrain$"

MoveTutor_EventScript_FateBadge_Text_4:
	.string "Flare Blitz$"

MoveTutor_EventScript_FateBadge_Text_5:
	.string "Draco Meteor$"

MoveTutor_EventScript_FateBadge_Text_6:
	.string "Steel Beam$"

MoveTutor_EventScript_FateBadge_Text_7:
	.string "Poltergeist$"

MoveTutor_EventScript_FateBadge_Text_8:
	.string "Supercell Slam$"

MoveTutor_EventScript_FateBadge_Text_9:
	.string "Meteor Beam$"



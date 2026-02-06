QuilspringTown_Gym_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, QuilspringTown_Gym_OnFrame
	map_script MAP_SCRIPT_ON_LOAD, QuilspringTown_Gym_OnLoad
	.byte 0

QuilspringTown_Gym_OnFrame:
	map_script_2 VAR_STORY, 12, QuilspringTown_Gym_EventScript_JimSpeech
	.2byte 0

QuilspringTown_Gym_OnLoad:
	call_if_set FLAG_SYS_QUILSPRING_PUZZLE_COMPLETED, QuilspringTown_Gym_EventScript_ShowSecretDoor
	end

QuilspringTown_Gym_EventScript_ShowSecretDoor::
	setmetatile 11, 19, METATILE_Indoor_NonDoor, FALSE
	return

Speaker_Clara:
    .string "Clara$"

QuilspringTown_Gym_EventScript_Clara::
	trainerbattle_single TRAINER_CLARA, QuilspringTown_Gym_Text_ClaraIntro, QuilspringTown_Gym_Text_ClaraDefeat
	setspeaker Speaker_Clara
	msgbox QuilspringTown_Gym_Text_ClaraPostBattle, MSGBOX_AUTOCLOSE
	end

Speaker_Annika:
    .string "Annika$"

QuilspringTown_Gym_EventScript_Annika::
	trainerbattle_single TRAINER_ANNIKA, QuilspringTown_Gym_Text_AnnikaIntro, QuilspringTown_Gym_Text_AnnikaDefeat
	setspeaker Speaker_Annika
	msgbox QuilspringTown_Gym_Text_AnnikaPostBattle, MSGBOX_AUTOCLOSE
	end

Speaker_Tiana:
    .string "Tiana$"

QuilspringTown_Gym_EventScript_Tiana::
	trainerbattle_single TRAINER_TIANA, QuilspringTown_Gym_Text_TianaIntro, QuilspringTown_Gym_Text_TianaDefeat
	setspeaker Speaker_Tiana
	msgbox QuilspringTown_Gym_Text_TianaPostBattle, MSGBOX_AUTOCLOSE
	end

QuilspringTown_Gym_EventScript_FoundSwitch::
	call_if_defeated TRAINER_CLARA, QuilspringTown_Gym_EventScript_CheckSwitch
	msgbox QuilspringTown_Gym_Text_FilledWithBooks, MSGBOX_AUTOCLOSE
	end

QuilspringTown_Gym_EventScript_CheckSwitch::
	call_if_defeated TRAINER_ANNIKA, QuilspringTown_Gym_EventScript_ActivateSwitch
	msgbox QuilspringTown_Gym_Text_FilledWithBooks, MSGBOX_AUTOCLOSE
	end

QuilspringTown_Gym_EventScript_ActivateSwitch::
	call_if_unset FLAG_SYS_QUILSPRING_PUZZLE_COMPLETED, QuilspringTown_Gym_EventScript_PressSwitch
	lockall
	msgbox QuilspringTown_Gym_Text_AlreadyPressed, MSGBOX_AUTOCLOSE
	releaseall
	end

QuilspringTown_Gym_EventScript_PressSwitch::
	lockall
	msgbox QuilspringTown_Gym_Text_YouFoundIt, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, QuilspringTown_Gym_EventScript_YouPressedIt
	msgbox QuilspringTown_Gym_Text_BookBack, MSGBOX_AUTOCLOSE	
	releaseall
	end

QuilspringTown_Gym_EventScript_YouPressedIt::
	msgbox QuilspringTown_Gym_Text_PressSwitch, MSGBOX_DEFAULT
	closemessage
	playse SE_DOOR
	delay 40
	setmetatile 11, 19, METATILE_Indoor_NonDoor, FALSE
	special DrawWholeMapView
	setflag FLAG_SYS_QUILSPRING_PUZZLE_COMPLETED
	releaseall
	end

QuilspringTown_Gym_Text_AlreadyPressed:
	.string "The switch has already been pressed.$"

QuilspringTown_Gym_Text_YouFoundIt:
	.string "{PLAYER} picked up the book and looked\n"
	.string "at the cover:\p"
	.string "'A Court of Ferrothorns and Roserades'\n"
	.string "by Sarah J. Maushold\p"
	.string "Do you want to open the book?$"

QuilspringTown_Gym_Text_BookBack:
	.string "{PLAYER} put the book back on the shelf.$"

QuilspringTown_Gym_Text_PressSwitch:
	.string "There is a hidden switch inside!\n"
	.string "{PLAYER} pressed the switch.$"

QuilspringTown_Gym_Text_FilledWithBooks:
	.string "It's filled with all sorts of books.$"

QuilspringTown_Gym_Text_GoodBook:
	.string "{PLAYER} read a couple of pages...\p"
	.string "It seems to be a good read so far,\n"
	.string "but nothing is hidden in the pages.$"

QuilspringTown_Gym_EventScript_GoodBook::
	msgbox QuilspringTown_Gym_Text_GoodBook, MSGBOX_DEFAULT
	closemessage
	msgbox QuilspringTown_Gym_Text_BookBack, MSGBOX_AUTOCLOSE	
	releaseall
	end

QuilspringTown_Gym_EventScript_Book_1::
	lockall
	msgbox QuilspringTown_Gym_Text_Book_1, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, QuilspringTown_Gym_EventScript_GoodBook
	msgbox QuilspringTown_Gym_Text_BookBack, MSGBOX_AUTOCLOSE	
	releaseall
	end

QuilspringTown_Gym_EventScript_Book_2::
	lockall
	msgbox QuilspringTown_Gym_Text_Book_2, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, QuilspringTown_Gym_EventScript_GoodBook
	msgbox QuilspringTown_Gym_Text_BookBack, MSGBOX_AUTOCLOSE	
	releaseall
	end

QuilspringTown_Gym_EventScript_Book_3::
	lockall
	msgbox QuilspringTown_Gym_Text_Book_3, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, QuilspringTown_Gym_EventScript_GoodBook
	msgbox QuilspringTown_Gym_Text_BookBack, MSGBOX_AUTOCLOSE	
	releaseall
	end

QuilspringTown_Gym_EventScript_Book_4::
	lockall
	msgbox QuilspringTown_Gym_Text_Book_4, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, QuilspringTown_Gym_EventScript_GoodBook
	msgbox QuilspringTown_Gym_Text_BookBack, MSGBOX_AUTOCLOSE	
	releaseall
	end

QuilspringTown_Gym_EventScript_Book_5::
	lockall
	msgbox QuilspringTown_Gym_Text_Book_5, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, QuilspringTown_Gym_EventScript_GoodBook
	msgbox QuilspringTown_Gym_Text_BookBack, MSGBOX_AUTOCLOSE	
	releaseall
	end

QuilspringTown_Gym_EventScript_Book_6::
	lockall
	msgbox QuilspringTown_Gym_Text_Book_6, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, QuilspringTown_Gym_EventScript_GoodBook
	msgbox QuilspringTown_Gym_Text_BookBack, MSGBOX_AUTOCLOSE	
	releaseall
	end

QuilspringTown_Gym_EventScript_Book_7::
	lockall
	msgbox QuilspringTown_Gym_Text_Book_7, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, QuilspringTown_Gym_EventScript_GoodBook
	msgbox QuilspringTown_Gym_Text_BookBack, MSGBOX_AUTOCLOSE	
	releaseall
	end

QuilspringTown_Gym_EventScript_Book_8::
	lockall
	msgbox QuilspringTown_Gym_Text_Book_8, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, QuilspringTown_Gym_EventScript_GoodBook
	msgbox QuilspringTown_Gym_Text_BookBack, MSGBOX_AUTOCLOSE	
	releaseall
	end

QuilspringTown_Gym_EventScript_Book_9::
	lockall
	msgbox QuilspringTown_Gym_Text_Book_9, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, QuilspringTown_Gym_EventScript_GoodBook
	msgbox QuilspringTown_Gym_Text_BookBack, MSGBOX_AUTOCLOSE	
	releaseall
	end

QuilspringTown_Gym_EventScript_Book_10::
	lockall
	msgbox QuilspringTown_Gym_Text_Book_10, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, QuilspringTown_Gym_EventScript_GoodBook
	msgbox QuilspringTown_Gym_Text_BookBack, MSGBOX_AUTOCLOSE	
	releaseall
	end

QuilspringTown_Gym_Text_Book_1:
	.string "{PLAYER} picked up the book and looked\n"
	.string "at the cover:\p"
	.string "'Fourth Wingull'\n"
	.string "by Rabsca Yarros\p"
	.string "Do you want to open the book?$"

QuilspringTown_Gym_Text_Book_2:
	.string "{PLAYER} picked up the book and looked\n"
	.string "at the cover:\p"
	.string "'The Luvdisc Hypothesis'\n"
	.string "by Ali Sudowoodo\p"
	.string "Do you want to open the book?$"

QuilspringTown_Gym_Text_Book_3:
	.string "{PLAYER} picked up the book and looked\n"
	.string "at the cover:\p"
	.string "'Lumineon Gods'\n"
	.string "by Kartana Robert\p"
	.string "Do you want to open the book?$"

QuilspringTown_Gym_Text_Book_4:
	.string "{PLAYER} picked up the book and looked\n"
	.string "at the cover:\p"
	.string "'Fifty Shades of Greavard'\n"
	.string "by Shellder James\p"
	.string "Do you want to open the book?$"

QuilspringTown_Gym_Text_Book_5:
	.string "{PLAYER} picked up the book and looked\n"
	.string "at the cover:\p"
	.string "'A Touch of Darkrai'\n"
	.string "by Scarlett St. Dragonair\p"
	.string "Do you want to open the book?$"

QuilspringTown_Gym_Text_Book_6:
	.string "{PLAYER} picked up the book and looked\n"
	.string "at the cover:\p"
	.string "'Eiscuebreaker'\n"
	.string "by Hannah Cinderace\p"
	.string "Do you want to open the book?$"

QuilspringTown_Gym_Text_Book_7:
	.string "{PLAYER} picked up the book and looked\n"
	.string "at the cover:\p"
	.string "'Heracrossed'\n"
	.string "by Cradily McIntire\p"
	.string "Do you want to open the book?$"

QuilspringTown_Gym_Text_Book_8:
	.string "{PLAYER} picked up the book and looked\n"
	.string "at the cover:\p"
	.string "'Den of Sevipers'\n"
	.string "by K.A. Corviknight\p"
	.string "Do you want to open the book?$"

QuilspringTown_Gym_Text_Book_9:
	.string "{PLAYER} picked up the book and looked\n"
	.string "at the cover:\p"
	.string "'Littens Out'\n"
	.string "by Forretress Allen\p"
	.string "Do you want to open the book?$"

QuilspringTown_Gym_Text_Book_10:
	.string "{PLAYER} picked up the book and looked\n"
	.string "at the cover:\p"
	.string "'Heatran's Rivalry'\n"
	.string "by Rachel Reuniclus\p"
	.string "Do you want to open the book?$"

Speaker_Nyx:
	.string "Nyx$"

QuilspringTown_Gym_EventScript_Nyx::
	lockall
	trainerbattle_single TRAINER_NYX, QuilspringTown_Gym_Text_NyxIntro, QuilspringTown_Gym_Text_NyxDefeat, QuilspringTown_Gym_EventScript_NyxDefeated, NO_MUSIC
	goto_if_unset FLAG_RECEIVED_TM_SNARL, QuilspringTown_Gym_EventScript_GiveSnarl
	setspeaker Speaker_Nyx
	msgbox QuilspringTown_Gym_Text_NyxPostBattle, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

QuilspringTown_Gym_EventScript_NyxDefeated::
	message QuilspringTown_Gym_Text_ReceivedInkBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	setspeaker Speaker_Nyx
	msgbox QuilspringTown_Gym_Text_InkBadgeInfoTakeThis, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_DEFEATED_QUILSPRING_GYM
	setflag FLAG_BADGE01_GET
	setvar VAR_LEVEL_CAP, 24
	setvar VAR_0x8008, 1
	call Common_EventScript_SetGymTrainers
	goto QuilspringTown_Gym_EventScript_GiveSnarl
	end

QuilspringTown_Gym_EventScript_GiveSnarl::
	giveitem ITEM_TM_SNARL
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM_SNARL
	setspeaker Speaker_Nyx
	msgbox QuilspringTown_Gym_Text_ExplainSnarl, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

QuilspringTown_Gym_Text_NyxIntro:
	.string "'The alpha king snarled at the horde\n"
	.string "of enemies that stood before them.\l"
	.string "'You will not lay a hand on my mate.''\p"
	.string "That is a excerpt from a new book I've\n"
	.string "been reading recently.\p"
	.string "While I am the Leader of Quilspring Town,\n"
	.string "I'd much prefer to reading in the dark\l"
	.string "with my Pokémon.\p"
	.string "You wish to challenge me? I've not had\n"
	.string "a good battle in a very long time.\p"
	.string "Very well, I hope you show me a battle\n"
	.string "as exciting as my books!$"

QuilspringTown_Gym_Text_NyxDefeat:
	.string "How thrilling! Finally, a battle\n"
	.string "to rival those from my books.\p"
	.string "Please accept the Pokémon League\n"
	.string "Ink Badge as a symbol of your win.$"

QuilspringTown_Gym_Text_ReceivedInkBadge:
	.string "{PLAYER} received the Ink Badge\n"
	.string "from Nyx.$"

QuilspringTown_Gym_Text_InkBadgeInfoTakeThis:
	.string "The Ink Badge is the first step\n"
	.string "in challenging the Pokémon League.\p"
	.string "You should take this with you.$"

QuilspringTown_Gym_Text_ExplainSnarl:
	.string "This Technical Machine, TM54,\n"
	.string "contains the move Snarl.\p"
	.string "It not only inflicts damage, but also\n"
	.string "lowers your opponent's Special Attack.\p"
	.string "It's a terrifying move, and an attack\n"
	.string "made for those who love the kind of\l"
	.string "books that I do.\p"
	.string "Oh, and you should know that any TM can\n"
	.string "be used as many time as you wish.$"

QuilspringTown_Gym_Text_NyxPostBattle:
	.string "You should challenge other Gym Leaders\n"
	.string "across Serenado to improve your skills.\p"
	.string "Your next adventure awaits you!$"

Speaker_Jim:
	.string "Jim$"

QuilspringTown_Gym_EventScript_JimSpeech::
	lockall
	applymovement LOCALID_JIM, Common_Movement_ExclamationMark
	waitmovement 0
	playse SE_PIN
	delay 10
	applymovement LOCALID_JIM, QuilspringTown_Gym_Movement_JimStart
	waitmovement 0
	setspeaker Speaker_Jim
	msgbox QuilspringTown_Gym_Text_JimSpeech, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_JIM, QuilspringTown_Gym_Movement_JimEnd
	waitmovement 0
	setvar VAR_STORY, 13
	releaseall
	end

QuilspringTown_Gym_EventScript_Jim::
	lockall
	faceplayer
	goto_if_set FLAG_DEFEATED_QUILSPRING_GYM, QuilspringTown_Gym_EventScript_JimPostVictory
	setspeaker Speaker_Jim
	msgbox QuilspringTown_Gym_Text_JimAdvice, MSGBOX_NPC
	closemessage
	releaseall
	end

QuilspringTown_Gym_EventScript_JimPostVictory::
	setspeaker Speaker_Jim
	msgbox QuilspringTown_Gym_Text_JimPostVictory, MSGBOX_NPC
	closemessage
	releaseall
	end

QuilspringTown_Gym_Text_JimSpeech:
	.string "Ah hello there, you must be a new\n"
	.string "challenger! I'm Jim, the Gym Guide!\p"
	.string "Welcome to your first step in the\n"
	.string "Serenado Pokémon League!\p"
	.string "It's my job to help Trainers navigate\n"
	.string "the League Challenge.\p"
	.string "I can see that you have a certain look\n"
	.string "of determination in your eyes,\p"
	.string "I think you have what it takes to go\n"
	.string "all the way and become the Champion!\p"
	.string "And at each step I'll be there to\n"
	.string "provide expert advice.\p"
	.string "The Quilspring Town Gym Leader, Nyx,\n"
	.string "is a fan of Dark-type Pokémon,\p"
	.string "but instead of actually battling\n"
	.string "challengers I hear she prefers to\l"
	.string "read ..uhh.. interesting books...\p"
	.string "Anyways, she's hidden herself away\n"
	.string "somewhere! Try talking to the Gym\l"
	.string "Trainers, they might help you.\p"
	.string "And remember, Dark-types really don't\n"
	.string "like Fairy, Bug, or Fighting Pokémon,\l"
	.string "so try bringing some of those!\p"
	.string "Good luck, I know you can do this!$"

QuilspringTown_Gym_Text_JimAdvice:
	.string "The Quilspring Town Gym Leader, Nyx,\n"
	.string "is a fan of Dark-type Pokémon.\p"
	.string "Dark-types really don't like Fairy,\n"
	.string "Bug, or Fighting-type Pokémon.\p"
	.string "Good luck, I know you can do this!$"

QuilspringTown_Gym_Text_JimPostVictory:
	.string "You did it, what a great battle!\n"
	.string "Check your Trainer Card.\p"
	.string "You'll see the Ink Badge, proof of\n"
	.string "your victory here.\p"
	.string "You're now on your way to climbing\n"
	.string "the ranks of the Pokémon League!\l"
	.string "Congratulations!$"

QuilspringTown_Gym_Movement_JimStart:
	walk_left
	walk_left
	walk_left
	face_down
	step_end

QuilspringTown_Gym_Movement_JimEnd:
	walk_right
	walk_right
	walk_right
	face_down
	step_end

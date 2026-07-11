Route7_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route7_OnFrame
	.byte 0

Route7_OnFrame:
	map_script_2 VAR_STORY, 5, Route7_EventScript_Unown
	map_script_2 VAR_STORY, 7, Route7_EventScript_Pokedex
	.2byte 0

Speaker_Isabel:
    .string "Isabel$"

Speaker_Unknown:
    .string "???$"

Speaker_Pine:
    .string "Prof. Pine$"

Speaker_Berith:
    .string "Berith$"

Route_7_EventScript_JamesEntrance_1::
	lockall
	applymovement LOCALID_JAMES, Route_7_Movement_JamesEntrance_1
	waitmovement 0
	setspeaker Speaker_James
	msgbox Route_7_Text_JamesEntrance, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, Common_Movement_WalkUp
	waitmovement 0
	applymovement LOCALID_JAMES, Route_7_Movement_JamesExit_1
	applymovement LOCALID_PLAYER, Route_7_Movement_PlayerExit_1
	waitmovement 0
	call Route_7_EventScript_BeforeCave
	releaseall
	end

Route_7_EventScript_JamesEntrance_2::
	lockall
	applymovement LOCALID_JAMES, Route_7_Movement_JamesEntrance_2
	waitmovement 0
	setspeaker Speaker_James
	msgbox Route_7_Text_JamesEntrance, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, Common_Movement_WalkUp
	waitmovement 0
	applymovement LOCALID_JAMES, Route_7_Movement_JamesExit_2
	applymovement LOCALID_PLAYER, Route_7_Movement_PlayerExit_2
	waitmovement 0
	call Route_7_EventScript_BeforeCave
	releaseall
	end

Route_7_EventScript_JamesEntrance_3::
	lockall
	applymovement LOCALID_JAMES, Route_7_Movement_JamesEntrance_3
	waitmovement 0
	setspeaker Speaker_James
	msgbox Route_7_Text_JamesEntrance, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, Common_Movement_WalkUp
	waitmovement 0
	applymovement LOCALID_JAMES, Route_7_Movement_JamesExit_3
	applymovement LOCALID_PLAYER, Route_7_Movement_PlayerExit_3
	waitmovement 0
	call Route_7_EventScript_BeforeCave
	releaseall
	end

Route_7_Movement_JamesEntrance_1:
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

Route_7_Movement_JamesEntrance_2:
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

Route_7_Movement_JamesEntrance_3:
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

Route_7_Text_JamesEntrance:
	.string "There you are, finally!\p"
	.string "Isabel is already waiting for us\n"
	.string "near the cave, let's go!$"

Route_7_Movement_JamesExit_1:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	step_end

Route_7_Movement_PlayerExit_1:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	face_up
	step_end

Route_7_Movement_JamesExit_2:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	step_end

Route_7_Movement_PlayerExit_2:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	face_up
	step_end

Route_7_Movement_JamesExit_3:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	step_end

Route_7_Movement_PlayerExit_3:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	face_up
	step_end

Route_7_EventScript_BeforeCave::
	applymovement LOCALID_ISABEL, Common_Movement_ExclamationMark
	waitmovement 0
	playse SE_PIN
	setspeaker Speaker_Isabel
	msgbox Route_7_Text_IsabelEntrance, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_JAMES, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	setspeaker Speaker_James
	msgbox Route_7_Text_JamesRetort, MSGBOX_DEFAULT
	closemessage
	setspeaker Speaker_Isabel
	msgbox Route_7_Text_IsabelRetort, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ISABEL, Route_7_Movement_IsabelToCave
	waitmovement 0
	removeobject LOCALID_ISABEL
	playse SE_EXIT
	setflag FLAG_UNUSED_0x054
	applymovement LOCALID_JAMES, Common_Movement_WalkRight
	waitmovement 0
	applymovement LOCALID_JAMES, Common_Movement_FaceDown
	waitmovement 0
	setspeaker Speaker_James
	msgbox Route_7_Text_JamesEnterCave, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_JAMES, Common_Movement_WalkUp
	waitmovement 0
	removeobject LOCALID_JAMES
	playse SE_EXIT
	applymovement LOCALID_PLAYER, Common_Movement_WalkUp2
	waitmovement 0
	playse SE_EXIT
	warpsilent MAP_ROUTE7_1F, 0
	releaseall
	end
	
Route_7_Text_IsabelEntrance:
	.string "Finally! What took you so long?\p"
	.string "Let's get inside the cave, I have\n"
	.string "research and recording to do!$"

Route_7_Text_JamesRetort:
	.string "Hey! It's not my fault, I was waiting\n"
	.string "on {PLAYER}. Besides, we are here\l"
	.string "to train my Pokémon, not for you!$"

Route_7_Text_IsabelRetort:
	.string "Whatever, let's go already!$"

Route_7_Movement_IsabelToCave:
	walk_left
	walk_up
	step_end

Route_7_Text_JamesEnterCave:
	.string "Jeez, what's her problem?$"	

Route7_EventScript_Unown::
	lockall
	setspeaker Speaker_James
	msgbox Route_7_Text_JamesWoah, MSGBOX_DEFAULT
	closemessage
	setspeaker Speaker_Isabel
	msgbox Route_7_Text_IsabelSomehow, MSGBOX_DEFAULT
	closemessage
	setspeaker Speaker_Unknown
	msgbox Route_7_Text_PineWhat, MSGBOX_DEFAULT
	closemessage
	special SpawnCameraObject
	applymovement LOCALID_CAMERA, Common_Movement_WalkDown2
	waitmovement 0
	applymovement LOCALID_PINE, Route7_Movement_PineApproach
	applymovement LOCALID_BERITH, Route7_Movement_PineApproach
	delay 10
	applymovement LOCALID_PLAYER, Common_Movement_FaceLeft
	applymovement LOCALID_JAMES_2, Common_Movement_FaceLeft
	delay 5
	playse SE_PIN
	applymovement LOCALID_ISABEL_2, Common_Movement_ExclamationMark
	waitmovement 0
	setspeaker Speaker_Isabel
	msgbox Route_7_Text_IsabelPine, MSGBOX_DEFAULT
	closemessage
	playse SE_PIN
	applymovement LOCALID_PLAYER, Common_Movement_ExclamationMark
	delay 2
	applymovement LOCALID_JAMES_2, Common_Movement_ExclamationMark
	waitmovement 0
	setspeaker Speaker_Pine
	msgbox Route_7_Text_PineAh, MSGBOX_DEFAULT
	closemessage
	setspeaker Speaker_James
	msgbox Route_7_Text_JamesWild, MSGBOX_DEFAULT
	closemessage
	setspeaker Speaker_Isabel
	msgbox Route_7_Text_IsabelProtect, MSGBOX_DEFAULT
	closemessage
	playse SE_PIN
	applymovement LOCALID_PINE, Common_Movement_ExclamationMark
	applymovement LOCALID_BERITH, Common_Movement_ExclamationMark
	waitmovement 0
	delay 8
	applymovement LOCALID_BERITH, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	setspeaker Speaker_Unknown
	msgbox Route_7_Text_BerithImpossible, MSGBOX_DEFAULT
	closemessage
	setspeaker Speaker_Isabel
	msgbox Route_7_Text_IsabelResearch, MSGBOX_DEFAULT
	closemessage
	playse SE_PIN
	applymovement LOCALID_BERITH, Common_Movement_ExclamationMark
	waitmovement 0
	setspeaker Speaker_Unknown
	msgbox Route_7_Text_BerithRune, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, Route7_Movement_PlayerOut
	applymovement LOCALID_BERITH, Route7_Movement_BerithTo
	waitmovement 0
	delay 10
	hideobjectat LOCALID_BERITH, MAP_ROUTE7
	playse SE_EXIT
	setspeaker Speaker_Pine
	msgbox Route_7_Text_PineApologies, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_JAMES_2, Common_Movement_FaceDown
	waitmovement 0
	applymovement LOCALID_JAMES_2, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	setspeaker Speaker_James
	msgbox Route_7_Text_JamesPlayer, MSGBOX_DEFAULT
	closemessage
	setspeaker Speaker_Pine
	msgbox Route_7_Text_PineToPlayer, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PINE, Common_Movement_ExclamationMark
	waitmovement 0
	setspeaker Speaker_Pine
	msgbox Route_7_Text_PineNeedPokemon, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BERITH, Common_Movement_FaceDown
	waitmovement 0
	showobjectat LOCALID_BERITH, MAP_ROUTE7
	applymovement LOCALID_BERITH, Common_Movement_WalkDown
	waitmovement 0
	playse SE_EXIT
	delay 6
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	applymovement LOCALID_ISABEL_2, Common_Movement_FaceUp
	applymovement LOCALID_JAMES_2, Common_Movement_FaceUp
	waitmovement 0
	setspeaker Speaker_Berith
	msgbox Route_7_Text_BerithTrue, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PINE, Common_Movement_ExclamationMark
	waitmovement 0
	setspeaker Speaker_Pine
	msgbox Route_7_Text_PineTeam, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, Common_Movement_FaceLeft
	applymovement LOCALID_ISABEL_2, Common_Movement_FaceLeft
	applymovement LOCALID_JAMES_2, Common_Movement_FaceLeft
	waitmovement 0
	setspeaker Speaker_Pine
	msgbox Route_7_Text_PineNeedPokemon2, MSGBOX_DEFAULT
	closemessage
	addobject LOCALID_BAG
	applymovement LOCALID_JAMES_2, Route7_Movement_JamesAway
	waitmovement 0
	special RemoveCameraObject
	setvar VAR_STORY, 6
	releaseall
	end

Route_7_Text_JamesWoah:
	.string "Whoa that was a close one!$"

Route7_Movement_PineApproach:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

Route_7_Text_IsabelSomehow:
	.string "Somehow we made it out.$"

Route_7_Text_PineWhat:
	.string "What is going on here?$"

Route_7_Text_IsabelPine:
	.string "Professor Pine!?$"

Route_7_Text_PineAh:
	.string "Ah yes, we were nearby and\n"
	.string "heard shouting from over here!\l"
	.string "Is everything okay?$"

Route_7_Text_JamesWild:
	.string "Professor, it was wild!\p"
	.string "We were in the cave and out of\n"
	.string "nowhere these three Zubat came and\l"
	.string "attacked us!$"

Route_7_Text_IsabelProtect:
	.string "If it were not for {PLAYER}\n"
	.string "and the Pokémon that protected us,\p"
	.string "we wouldn't have made it out!\n"
	.string "I think it was Unown who saved us!$"

Route_7_Text_BerithImpossible:
	.string "That's impossible!\p"
	.string "Unown haven't been seen here in\n"
	.string "centuries, the only reason we know\p"
	.string "they exist in the first place is\n"
	.string "references in ancient texts!$"

Route_7_Text_IsabelResearch:
	.string "It's all true I promise you!\n"
	.string "I've done my research!\p"
	.string "Besides, it matches the description\n"
	.string "laid out in the runes in the cave.$"

Route_7_Text_BerithRune:
	.string "What?\p"
	.string "I've never heard of anything like\n"
	.string "that in this cave!$"

Route7_Movement_BerithTo:
	walk_right
	walk_up
	walk_up
	walk_right
	walk_right
	walk_up
	step_end

Route7_Movement_PlayerOut:
	walk_down
	walk_down
	face_left
	step_end

Route_7_Text_PineApologies:
	.string "I apologize for my colleague.\p"
	.string "That is Berith, one of Serenado's\n"
	.string "leading religious figures and a\l"
	.string "fellow lecturer at the University.\p"
	.string "He means well, but as a leading expert\n"
	.string "on the natives of ancient Serenado,\p"
	.string "he expects to know of every artifact\n"
	.string "and rune in the entire region.\p"
	.string "Hearing about something he does not\n"
	.string "know of is upsetting to him.\p"
	.string "Now, let's move on!\p"
	.string "What is this I hear about one of you\n"
	.string "controlling an Unown?$"

Route_7_Text_JamesPlayer:
	.string "It was {PLAYER}!\n"
	.string "They were incredible!$"

Route_7_Text_PineToPlayer:
	.string "Ah let me take a look at you. You\n"
	.string "don't have a Pokémon yet, do you?\p"
	.string "Unown are a Pokémon from ancient times,\n"
	.string "said to be messengers of the gods.\p"
	.string "They haven't been seen in many years,\n"
	.string "much less controlled by a Trainer.$"

Route_7_Text_PineNeedPokemon:
	.string "I guess you aren't a Trainer though,\n"
	.string "well not yet! You need your own Pokémon!\p"
	.string "I've been a Professor for years now, and\n"
	.string "I have seen many trainers come and go.\p"
	.string "I can tell you have what it takes to be a\n"
	.string "great Pokémon Trainer.\p"
	.string "Besides, I would trust anyone who can\n"
	.string "control an Unown in battle!$"

Route_7_Text_BerithTrue:
	.string "It's incredible!\p"
	.string "I've heard stories about texts like these,\n"
	.string "but I thought they were just legends!\l"
	.string "Professor, I must research these more!$"

Route_7_Text_PineTeam:
	.string "Yes absolutely!\p"
	.string "We'll have to get a team from the\n"
	.string "University over here at once!$"

Route_7_Text_PineNeedPokemon2:
	.string "Now, in my bag I have three Pokémon,\n"
	.string "the three Pokémon we give out to new\l"
	.string "Trainers in the Serenado region!\p"
	.string "Choose one of them to be your partner!$"

Route7_Movement_JamesAway:
	walk_up
	face_down
	step_end

Route7_EventScript_OpenBag::
	lockall
	call_if_eq VAR_STORY, 6, Route7_EventScript_Bag
	msgbox Route_7_Text_PineBag, MSGBOX_DEFAULT
	releaseall
	end

Route7_EventScript_Bag::
	lockall
	special ChooseStarter
	waitstate
	setflag FLAG_SYS_POKEMON_GET
	setvar VAR_STORY, 7
	releaseall
	end

Route7_EventScript_Pokedex::
	lockall
	setspeaker Speaker_Pine
	msgbox Route_7_Text_PineCongrats, MSGBOX_DEFAULT
	closemessage
	playfanfare MUS_OBTAIN_ITEM
	msgbox Route7_Text_ReceivedPokedex, MSGBOX_DEFAULT
	waitfanfare
	setflag FLAG_SYS_POKEDEX_GET
	setflag FLAG_ADVENTURE_STARTED
	special SetUnlockedPokedexFlags
	setflag FLAG_RECEIVED_POKEDEX_FROM_BIRCH
	setflag FLAG_SYS_NATIONAL_DEX
	special EnableNationalPokedex
	setspeaker Speaker_Pine
	msgbox Route_7_Text_PineMustApologize, MSGBOX_DEFAULT
	closemessage
	delay 4
	applymovement LOCALID_JAMES_2, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	setspeaker Speaker_James
	msgbox Route_7_Text_JamesMustBattle, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, Common_Movement_FaceLeft
	applymovement LOCALID_JAMES_2, Route7_Movement_JamesLeaveBattle
	waitmovement 0
	removeobject LOCALID_JAMES_2
	setspeaker Speaker_Pine
	msgbox Route_7_Text_GoMom, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BERITH, Common_Movement_FaceLeft
	waitmovement 0
	setspeaker Speaker_Berith
	msgbox Route_7_Text_BerithGo, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	applymovement LOCALID_BERITH, Common_Movement_FaceRight
	waitmovement 0
	setspeaker Speaker_Berith
	msgbox Route_7_Text_BerithSorry, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BERITH, Route7_Movement_BeginLeave
	waitmovement 0
	delay 5
	removeobject LOCALID_BAG
	applymovement LOCALID_PLAYER, Common_Movement_FaceLeft
	applymovement LOCALID_BERITH, Route7_Movement_FinishLeave
	applymovement LOCALID_PINE, Route7_Movement_FinishLeave
	waitmovement 0
	removeobject LOCALID_BERITH
	removeobject LOCALID_PINE
	setvar VAR_STORY, 8
	clearflag FLAG_CAIRWIND_MOVE
	releaseall
	end

Route_7_Text_PineBag:
	.string "Two Poké Balls sit in the bag.$"

Route_7_Text_PineCongrats:
	.string "A great choice of Pokémon!\p"
	.string "Now as a Pokémon Trainer you need\n"
	.string "to have one of these!$"

Route7_Text_ReceivedPokedex:
	.string "{PLAYER} received the Pokédex!$"

Route_7_Text_PineMustApologize:
	.string "Now I must apologize, usually I\n"
	.string "have a couple of other items to give\p"
	.string "to new Trainers, but with only my\n"
	.string "field bag on me, they are back in my lab.\p"
	.string "Please come see me in my lab at\n"
	.string "Serenado University in Quilspring Town,\p"
	.string "and I will make sure that you have\n"
	.string "everything you need.\p"
	.string "That will be convenient, as the first\n"
	.string "step in taking on the Pokémon League\l"
	.string "will be in that same town.$"

Route_7_Text_JamesMustBattle:
	.string "{PLAYER}, now that you have a Pokémon,\n"
	.string "we need to have a Pokémon battle!\l"
	.string "I'll be waiting on Route 1!$"

Route7_Movement_JamesLeaveBattle:
	walk_left
	walk_left
	walk_left
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

Route_7_Text_GoMom:
	.string "Now {PLAYER}, before you go on this\n"
	.string "journey, you should tell your mom!\p"
	.string "I will explain to her what happened\n"
	.string "here, but I know she will want to see\l"
	.string "you before you depart.\p"
	.string "Berith, let's go, and then we can\n"
	.string "return to our fieldwork here.$"

Route_7_Text_BerithGo:
	.string "Yes absolutely!$"
	
Route_7_Text_BerithSorry:
	.string "And I do apologize for my behavior\n"
	.string "earlier, I am perhaps a little too\l"
	.string "passionate about ancient history.$"

Route7_Movement_BeginLeave:
	walk_left
	walk_left
	walk_left
	face_down
	step_end

Route7_Movement_FinishLeave:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

Route_7_EventScript_IsabelStay::
	lockall
	setspeaker Speaker_Isabel
	msgbox Route_7_Text_IsabelStay, MSGBOX_NPC
	releaseall
	end

Route_7_Text_IsabelStay:
	.string "I know you have a journey to go on,\n"
	.string "But I think I'm going stay and\l"
	.string "do more research on the runes here!$"

Route7_EventScript_James::
	lockall
	setspeaker Speaker_James
	msgbox Route_7_Text_JamesDefault, MSGBOX_DEFAULT
	releaseall
	end

Route_7_Text_JamesDefault:
	.string "Whoa I can't believe you are getting\n"
	.string "a Pokémon from the Professor!$"

Route7_EventScript_BerithDefault::
	lockall
	setspeaker Speaker_Berith
	msgbox Route_7_Text_BerithDefault, MSGBOX_DEFAULT
	releaseall
	end

Route_7_Text_BerithDefault:
	.string "You have a big decision to make!\n"
	.string "But there is not a bad choice.$"

Route_7_EventScript_StopLeft::
	lockall
	msgbox Route_7_Text_GetPokemon, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, Common_Movement_WalkRight
	waitmovement 0
	releaseall
	end

Route_7_Text_GetPokemon:
	.string "I should choose a Pokémon\n"
	.string "before leaving.$"

Route_7_EventScript_StopMiddle::
	lockall
	msgbox Route_7_Text_NoPokemon, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, Common_Movement_WalkUp
	waitmovement 0
	releaseall
	end

Route_7_Text_NoPokemon:
	.string "I can't go in the tall grass\n"
	.string "without a Pokémon!$"

Route_7_EventScript_StopRight::
	lockall
	msgbox Route_7_Text_NoPokemon, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, Common_Movement_WalkLeft
	waitmovement 0
	releaseall
	end

Speaker_Selena:
    .string "Selena$"

Route7_EventScript_Selena::
	trainerbattle_single TRAINER_SELENA, Route7_Text_SelenaIntro, Route7_Text_SelenaDefeat
	setspeaker Speaker_Selena
	msgbox Route7_Text_SelenaPostBattle, MSGBOX_AUTOCLOSE
	end

Speaker_Gabe:
    .string "Gabe$"

Route7_EventScript_Gabe::
	trainerbattle_single TRAINER_GABE, Route7_Text_GabeIntro, Route7_Text_GabeDefeat
	setspeaker Speaker_Gabe
	msgbox Route7_Text_GabePostBattle, MSGBOX_AUTOCLOSE
	end

Speaker_Hiker:
    .string "Hiker$"

Route7_EventScript_Hiker::
	lockall
	setspeaker Speaker_Hiker
	msgbox Route7_Text_Hiker, MSGBOX_NPC
	releaseall
	end

Route7_Text_Hiker:
	.string "Be careful if you are trying through\n"
	.string "Route 7 to Cairwind Town!\p"
	.string "It's easy going down the mountain, but\n"
	.string "much harder climbing back up!$"


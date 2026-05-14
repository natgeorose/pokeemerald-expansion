Route1_MapScripts::
	.byte 0

Route_1_EventScript_JamesEntrance_1::
	delay 5
	applymovement LOCALID_JAMES, Common_Movement_FaceLeft
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_JAMES, Common_Movement_ExclamationMark
	waitmovement 0
	lockall
	applymovement LOCALID_PLAYER, Common_Movement_FaceRight
	applymovement LOCALID_JAMES, Route_1_Movement_JamesEntrance_1
	waitmovement 0
	call Route_1_EventScript_JamesBattle
	releaseall
	end

Route_1_EventScript_JamesEntrance_2::
	delay 5
	applymovement LOCALID_JAMES, Common_Movement_FaceLeft
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_JAMES, Common_Movement_ExclamationMark
	waitmovement 0
	lockall
	applymovement LOCALID_PLAYER, Common_Movement_FaceRight
	applymovement LOCALID_JAMES, Route_1_Movement_JamesEntrance_2
	waitmovement 0
	call Route_1_EventScript_JamesBattle
	releaseall
	end

Route_1_EventScript_JamesEntrance_3::
	delay 5
	applymovement LOCALID_JAMES, Common_Movement_FaceLeft
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_JAMES, Common_Movement_ExclamationMark
	waitmovement 0
	lockall
	applymovement LOCALID_PLAYER, Common_Movement_FaceRight
	applymovement LOCALID_JAMES, Route_1_Movement_JamesEntrance_3
	waitmovement 0
	call Route_1_EventScript_JamesBattle
	releaseall
	end

Route_1_Movement_JamesEntrance_1:
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

Route_1_Movement_JamesEntrance_2:
	walk_up
	walk_left
	walk_left
	walk_left
	step_end

Route_1_Movement_JamesEntrance_3:
	walk_up
	walk_left
	walk_left
	step_end

Route_1_EventScript_JamesBattle::
	lockall
	setspeaker Speaker_James
	msgbox Route_1_Text_JamesEnter, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_JAMES_1, Route_1_Text_JamesDefeat
	setspeaker Speaker_James
	msgbox Route_1_Text_JamesLeave, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_JAMES, Common_Movement_FaceDown
	waitmovement 0
	delay 15
	applymovement LOCALID_JAMES, Common_Movement_FaceLeft
	waitmovement 0
	setspeaker Speaker_James
	msgbox Route_1_Text_JamesRival, MSGBOX_DEFAULT
	closemessage
	giveitem ITEM_POKE_BALL, 5
	setspeaker Speaker_James
	msgbox Route_1_Text_JamesFinal, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, Common_Movement_WalkDown
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_FaceRight
	waitmovement 0
	delay 8
	applymovement LOCALID_JAMES, Route_1_Movement_JamesDefeat
	waitmovement 0
	removeobject LOCALID_JAMES
	setvar VAR_STORY, 10
	setflag FLAG_JAMES_ROUTE_1
	setflag FLAG_HIDE_QUILSPRING_ISABEL
	setflag FLAG_HIDE_QUILSPRING_JAMES
	clearflag FLAG_CAIRWIND_MART
	releaseall
	end

Route_1_Text_JamesEnter:
	.string "There you are {PLAYER}!\p"
	.string "Riolu and I have been training, we\n"
	.string "are ready for our first Pokémon battle!\p"
	.string "Hope you're ready for a fight!$"

Route_1_Text_JamesDefeat:
	.string "Whoa {PLAYER}, you're good!$"

Route_1_Text_JamesLeave:
	.string "You really are a natural, {PLAYER}.\p"
	.string "I even got Riolu before you got your\n"
	.string "Pokémon, and you still beat us.$"

Route_1_Text_JamesRival:
	.string "I guess I shouldn't be that hard on\n"
	.string "myself, we did get our Pokémon on\p"
	.string "the same day.\p"
	.string "That's it, we'll just have to train\n"
	.string "harder and win next time!\p"
	.string "First I have to ask my dad though,\n"
	.string "that will be the hard part.\p"
	.string "Oh, now that you're a real Pokémon\n"
	.string "Trainer you can use these!$"

Route_1_Text_JamesFinal:
	.string "I'm going to catch more Pokémon\n"
	.string "before our rematch!\p"
	.string "We will see you soon, I'm sure of it!$"

Route_1_Movement_JamesDefeat:
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

Speaker_Joey:
    .string "Joey$"

Speaker_Lily:
    .string "Lily$"

Speaker_Delia:
    .string "Delia$"

Speaker_Darian:
    .string "Darian$"

Route1_EventScript_Joey::
	trainerbattle_single TRAINER_JOEY, Route1_Text_JoeyIntro, Route1_Text_JoeyDefeat
	setspeaker Speaker_Joey
	msgbox Route1_Text_JoeyPostBattle, MSGBOX_AUTOCLOSE
	end

Route1_EventScript_Lily::
	trainerbattle_single TRAINER_LILY, Route1_Text_LilyIntro, Route1_Text_LilyDefeat
	setspeaker Speaker_Lily
	msgbox Route1_Text_LilyPostBattle, MSGBOX_AUTOCLOSE
	end

Route1_EventScript_Delia::
	trainerbattle_single TRAINER_DELIA, Route1_Text_DeliaIntro, Route1_Text_DeliaDefeat
	setspeaker Speaker_Delia
	msgbox Route1_Text_DeliaPostBattle, MSGBOX_AUTOCLOSE
	end

Route1_EventScript_Darian::
	trainerbattle_single TRAINER_DARIAN, Route1_Text_DarianIntro, Route1_Text_DarianDefeat
	setspeaker Speaker_Darian
	msgbox Route1_Text_DarianPostBattle, MSGBOX_AUTOCLOSE
	end

Speaker_Fisherman:
    .string "Fisherman$"

Route1_EventScript_FishingRodFisherman::
	lockall
	faceplayer
	goto_if_set FLAG_RECEIVED_SUPER_ROD, Route1_EventScript_ReceivedFishingRod
	setspeaker Speaker_Fisherman
	msgbox Route1_Text_YouWantFishingRod, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route1_EventScript_DeclineFishingRod
	setspeaker Speaker_Fisherman
	msgbox Route1_Text_FishingRodIsSuper, MSGBOX_DEFAULT
	giveitem ITEM_SUPER_ROD
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_SUPER_ROD
	setspeaker Speaker_Fisherman
	msgbox Route1_Text_TryDroppingRodInWater, MSGBOX_DEFAULT
	releaseall
	end

Route1_EventScript_ReceivedFishingRod::
	setspeaker Speaker_Fisherman
	msgbox Route1_Text_GoAfterWaterPokemon, MSGBOX_NPC
	releaseall
	end

Route1_EventScript_DeclineFishingRod::
	setspeaker Speaker_Fisherman
	msgbox Route1_Text_DontYouLikeToFish, MSGBOX_NPC
	releaseall
	end

Route1_Text_YouWantFishingRod:
	.string "Hey there, are you a new Trainer?\p"
	.string "Searching in tall grass for Pokémon\n"
	.string "can only get you so far!\p"
	.string "If you want to catch the best Water\n"
	.string "Pokémon that Serenado has to offer,\l"
	.string "you'll need to be able to fish!\p"
	.string "As a veteran fisherman, I always\n"
	.string "carry a spare Fishing Rod on me.\p"
	.string "What do you think?\n"
	.string "Do you want a Fishing Rod?$"

Route1_Text_FishingRodIsSuper:
	.string "Glad to hear it! You'll be fishing\n"
	.string "up the best Pokémon in no time!$"

Route1_Text_TryDroppingRodInWater:
	.string "If you're around water, try dropping\n"
	.string "in your Rod and see what bites!$"

Route1_Text_DontYouLikeToFish:
	.string "Really? You don't want to fish?\p"
	.string "Well as long as I have a spare\n"
	.string "Rod on me, my offer stands.$"

Route1_Text_GoAfterWaterPokemon:
	.string "Go catch some Pokémon with that\n"
	.string "Rod and make me proud!$"

Speaker_Gentleman:
    .string "Gentleman$"

Route1_EventScript_Gentleman::
	lockall
	faceplayer
	goto_if_set FLAG_ITEM_COALSCORCH_IRON, Route1_EventScript_ReceivedFullHeal
	setspeaker Speaker_Gentleman
	msgbox Route1_Text_GentlemanGiveItem, MSGBOX_DEFAULT
	closemessage	
	giveitem ITEM_FULL_HEAL
	setspeaker Speaker_Gentleman
	msgbox Route1_Text_GentlemanGoodLuck, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_ITEM_COALSCORCH_IRON
	releaseall
	end

Route1_EventScript_ReceivedFullHeal::
	lockall
	setspeaker Speaker_Gentleman
	msgbox Route1_Text_GentlemanGoodLuck, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

Route1_Text_GentlemanGiveItem:
	.string "Are you coming from Cairwind Town?\p"
	.string "Moorden Town is just up ahead, but\n"
	.string "if your objective is Quilspring Town\p"
	.string "you still have quite a ways to go.\p"
	.string "The road up ahead is treacherous,\n"
	.string "you should take this to help keep\l"
	.string "your Pokémon safe.$"

Route1_Text_GentlemanGoodLuck:
	.string "Good luck with your travels!$"

Speaker_BlackBelt:
    .string "Black Belt$"

Route1_EventScript_BlackBelt::
	lockall
	setspeaker Speaker_BlackBelt
	msgbox Route1_Text_BlackBelt, MSGBOX_NPC
	releaseall
	end

Route1_Text_BlackBelt:
	.string "This is my favorite spot to relax,\n"
	.string "the sound of water is so peaceful.\p"
	.string "I hope you can take a break and relax,\n"
	.string "Pokémon battles and adventures can be\l"
	.string "quite taxing, no matter your experience.$"

Route1_EventScript_LittleBoy::
	lockall
	setspeaker Speaker_Boy
	msgbox Route1_Text_LittleBoy, MSGBOX_NPC
	releaseall
	end

Route1_Text_LittleBoy:
	.string "Did you know that sometimes you can\n"
	.string "fight two wild Pokémon at once?\p"
	.string "If you have more than one Pokémon while\n"
	.string "walking in tall grass,\l"
	.string "multiple Pokémon could jump out at you!$"

Route1_EventScript_RouteSignCairwind::
	msgbox Route1_Text_RouteSignCairwind, MSGBOX_SIGN
	end

Route1_EventScript_RouteSignMoorden::
	msgbox Route1_Text_RouteSignMoorden, MSGBOX_SIGN
	end

Route1_Text_RouteSignCairwind:
	.string "Route 1\p"
	.string "{UP_ARROW} Cairwind Town\n"
	.string "{LEFT_ARROW} Moorden Village$"

Route1_Text_RouteSignMoorden:
	.string "Route 1\p"
	.string "{LEFT_ARROW} Moorden Village\n"
	.string "{RIGHT_ARROW} Cairwind Town$"


Route8_MapScripts::
	.byte 0

Route8_EventScript_EnterTop::
	lockall
	playse SE_PIN
	applymovement LOCALID_ROUTE8_JAMES, Common_Movement_ExclamationMark
	waitmovement
	applymovement LOCALID_ROUTE8_JAMES, Common_Movement_FaceLeft
	applymovement LOCALID_ROUTE8_ISABEL, Common_Movement_FaceLeft
	waitmovement
	setspeaker Speaker_James
	msgbox Route_8_Text_JamesThereYouAre, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, Route8_Movement_TopEnter
	waitmovement
	goto Route8_EventScript_MainBattle
	releaseall
	end

Route8_EventScript_EnterMiddle::
	lockall
	playse SE_PIN
	applymovement LOCALID_ROUTE8_JAMES, Common_Movement_ExclamationMark
	waitmovement
	applymovement LOCALID_ROUTE8_JAMES, Common_Movement_FaceLeft
	applymovement LOCALID_ROUTE8_ISABEL, Common_Movement_FaceLeft
	waitmovement
	setspeaker Speaker_James
	msgbox Route_8_Text_JamesThereYouAre, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, Route8_Movement_MiddleEnter
	waitmovement
	goto Route8_EventScript_MainBattle
	releaseall
	end

Route8_EventScript_EnterBottom::
	lockall
	playse SE_PIN
	applymovement LOCALID_ROUTE8_JAMES, Common_Movement_ExclamationMark
	waitmovement
	applymovement LOCALID_ROUTE8_JAMES, Common_Movement_FaceLeft
	applymovement LOCALID_ROUTE8_ISABEL, Common_Movement_FaceLeft
	waitmovement
	setspeaker Speaker_James
	msgbox Route_8_Text_JamesThereYouAre, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, Route8_Movement_BottomEnter
	waitmovement
	goto Route8_EventScript_MainBattle
	releaseall
	end

Route8_EventScript_MainBattle::
	setspeaker Speaker_Isabel
	msgbox Route_8_Text_IsabelQuarry, MSGBOX_DEFAULT
	closemessage
	fadescreenspeed FADE_TO_BLACK, 2
	message Route8_Text_PlayerExplain
	waitmessage
	fadescreenspeed FADE_FROM_BLACK, 2
	delay 8
	playse SE_PIN
	applymovement LOCALID_ROUTE8_JAMES, Common_Movement_ExclamationMark
	applymovement LOCALID_ROUTE8_ISABEL, Common_Movement_ExclamationMark
	waitmovement
	delay 3
	applymovement LOCALID_ROUTE8_JAMES, Common_Movement_WalkInPlaceFasterLeft
	waitmovement
	setspeaker Speaker_James
	msgbox Route_8_Text_JamesIncredible, MSGBOX_DEFAULT
	closemessage
	setspeaker Speaker_Isabel
	msgbox Route_8_Text_IsabelAvalanche, MSGBOX_DEFAULT
	closemessage
	setspeaker Speaker_James
	msgbox Route_8_Text_JamesTrain, MSGBOX_DEFAULT
	closemessage
	playse SE_PIN
	applymovement LOCALID_ROUTE8_JAMES, Common_Movement_ExclamationMark
	waitmovement
	delay 2
	applymovement LOCALID_ROUTE8_JAMES, Common_Movement_FaceDown
	applymovement LOCALID_ROUTE8_ISABEL, Common_Movement_FaceUp
	waitmovement
	setspeaker Speaker_James
	msgbox Route_8_Text_JamesIKnow, MSGBOX_DEFAULT
	closemessage
	playse SE_PIN
	applymovement LOCALID_ROUTE8_ISABEL, Common_Movement_ExclamationMark
	waitmovement
	applymovement LOCALID_ROUTE8_ISABEL, Common_Movement_WalkInPlaceFasterUp
	waitmovement
	setspeaker Speaker_Isabel
	msgbox Route_8_Text_IsabelIDontKnow, MSGBOX_DEFAULT
	closemessage
	setspeaker Speaker_James
	msgbox Route_8_Text_JamesItllBeFine, MSGBOX_DEFAULT
	closemessage
	setspeaker Speaker_Isabel
	msgbox Route_8_Text_IsabelAlrightThen, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ROUTE8_ISABEL, Common_Movement_FaceLeft
	applymovement LOCALID_ROUTE8_JAMES, Common_Movement_FaceLeft
	waitmovement
	setspeaker Speaker_Isabel
	msgbox Route_8_Text_IsabelGetReady, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_ISABEL_1, Route_8_Text_IsabelDefeat
	applymovement LOCALID_ROUTE8_JAMES, Common_Movement_WalkInPlaceFasterLeft
	waitmovement
	setspeaker Speaker_James
	msgbox Route_8_Text_JamesAwesome, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ROUTE8_ISABEL, Common_Movement_FaceUp
	applymovement LOCALID_ROUTE8_JAMES, Common_Movement_FaceDown
	waitmovement
	setspeaker Speaker_James
	msgbox Route_8_Text_JamesImproving, MSGBOX_DEFAULT
	closemessage
	setspeaker Speaker_Isabel
	msgbox Route_8_Text_IsabelThanks, MSGBOX_DEFAULT
	closemessage
	setspeaker Speaker_James
	msgbox Route_8_Text_JamesFairEnough, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ROUTE8_ISABEL, Common_Movement_FaceLeft
	applymovement LOCALID_ROUTE8_JAMES, Common_Movement_FaceLeft
	waitmovement
	setspeaker Speaker_James
	msgbox Route_8_Text_JamesWithThat, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ROUTE8_ISABEL, Common_Movement_WalkInPlaceFasterLeft
	waitmovement
	setspeaker Speaker_Isabel
	msgbox Route_8_Text_IsabelFinally, MSGBOX_DEFAULT
	closemessage
	setspeaker Speaker_James
	msgbox Route_8_Text_JamesYeah, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ROUTE8_ISABEL, Route8_Movement_BothLeave
	applymovement LOCALID_ROUTE8_JAMES, Route8_Movement_BothLeave
	waitmovement
	playse SE_PIN
	applymovement LOCALID_ROUTE8_JAMES, Common_Movement_ExclamationMark
	waitmovement
	applymovement LOCALID_ROUTE8_ISABEL, Common_Movement_FaceRight
	applymovement LOCALID_ROUTE8_JAMES, Common_Movement_FaceRight
	applymovement LOCALID_PLAYER, Common_Movement_FaceLeft
	waitmovement
	setspeaker Speaker_James
	msgbox Route_8_Text_JamesThirdGym, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ROUTE8_ISABEL, Route8_Movement_BothLeave
	applymovement LOCALID_ROUTE8_JAMES, Route8_Movement_BothLeave
	waitmovement
	removeobject LOCALID_ROUTE8_ISABEL
	removeobject LOCALID_ROUTE8_JAMES
	setvar VAR_STORY, 21
	setflag FLAG_HIDE_ROUTE8_JAMES
	releaseall
	end

Route_8_Text_JamesThereYouAre:
	.string "Hey {PLAYER}, there you are!\n"
	.string "Get over here!$"

Route_8_Text_IsabelQuarry:
	.string "Hi {PLAYER}, how were things in\n"
	.string "the quarry? Were the Chosen there?$"

Route8_Text_PlayerExplain:
	.string "{PLAYER} explained what happened\n"
	.string "in Coalscorch Quarry.$"

Route_8_Text_JamesIncredible:
	.string "So not only were there a ton of\n"
	.string "the Chosen in the quarry,\l"
	.string "but you defeated them all?!\p"
	.string "Including their admin?!?\p"
	.string "That's incredible!\n"
	.string "I wonder what they're after though.\p"
	.string "Our mission has not be going\n"
	.string "quite as well...$"

Route_8_Text_IsabelAvalanche:
	.string "There's an avalanche on Route 10,\n"
	.string "so we are stuck on this side of\l"
	.string "the mountains for now.$"

Route_8_Text_JamesTrain:
	.string "In the meantime, while we wait for\n"
	.string "the path to clear up,\p"
	.string "I've tried to teach Isabel some\n"
	.string "Pokémon battling!\p"
	.string "I thought we both should be\n"
	.string "prepared for the Chosen before\l"
	.string "arriving in Reme City.$"

Route_8_Text_JamesIKnow:
	.string "I know!\p"
	.string "Isabel, why don't you have a\n"
	.string "practice battle again {PLAYER}?\p"
	.string "You won't get better if you only\n"
	.string "train against me!$"

Route_8_Text_IsabelIDontKnow:
	.string "Uhh I'm not too sure about that,\n"
	.string "I just started training and {PLAYER}\l"
	.string "already has two Gym Badges...$"

Route_8_Text_JamesItllBeFine:
	.string "It'll be fine!\p"
	.string "Besides, you can learn more from\n"
	.string "a loss sometime than winning!$"

Route_8_Text_IsabelAlrightThen:
	.string "Well alright then, if you say so...$"

Route_8_Text_IsabelGetReady:
	.string "I'm not positive I'm ready for a\n"
	.string "real Pokémon battle, but I'll\l"
	.string "try my best!\p"
	.string "{PLAYER}, hope you are ready for\n"
	.string "a battle!$"

Route_8_Text_IsabelDefeat:
	.string "Yikes, you really are good!$"

Route_8_Text_JamesAwesome:
	.string "That was awesome!$"

Route_8_Text_JamesImproving:
	.string "And Isabel you are improving very\n"
	.string "quickly, that was a great battle\l"
	.string "to watch!$"

Route_8_Text_IsabelThanks:
	.string "Thanks, although I'm nowhere\n"
	.string "near the level of you two...\p"
	.string "I'm looking forward to when we\n"
	.string "can get back to the researching\l"
	.string "part of the professor's mission.$"

Route_8_Text_JamesFairEnough:
	.string "Fair enough, but don't doubt\n"
	.string "yourself too much! There's a lot\l"
	.string "to learn about battling.$"

Route_8_Text_JamesWithThat:
	.string "With that, I think we are going\n"
	.string "to head back to Fellhaven Town\l"
	.string "and rest up for now,\p"
	.string "while they are still working on\n"
	.string "clearing Route 10.\p"
	.string "We'll meet up with you over in\n"
	.string "Reme City later!$"

Route_8_Text_IsabelFinally:
	.string "Finally I can get out of this\n"
	.string "cold and go back to reading!$"

Route_8_Text_JamesYeah:
	.string "Yeah let's go then!$"

Route_8_Text_JamesThirdGym:
	.string "Oh and {PLAYER}, up the\n"
	.string "mountain is Veilbora Town,\p"
	.string "you should challenge the Gym there\n"
	.string "for your thrid badge!\p"
	.string "It'll be a good way of killing\n"
	.string "time before the route is open.\l"
	.string "Good luck!$"

Route8_Movement_TopEnter:
	walk_down
	walk_right
	walk_right
	step_end

Route8_Movement_MiddleEnter:
	walk_right
	walk_right
	step_end

Route8_Movement_BottomEnter:
	walk_up
	walk_right
	walk_right
	step_end

Route8_Movement_BothLeave:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

Route8_EventScript_RouteSign::
	msgbox Route8_Text_RouteSign, MSGBOX_SIGN
	end

Route8_Text_RouteSign:
	.string "Route 8\p"
	.string "{LEFT_ARROW} Fellhaven Town\n"
	.string "{RIGHT_ARROW} Veilbora Town$"

Speaker_Marcellus:
    .string "Marcellus$"

Route8_EventScript_Marcellus::
	trainerbattle_single TRAINER_MARCELLUS, Route8_Text_MarcellusIntro, Route8_Text_MarcellusDefeat
	setspeaker Speaker_Marcellus
	msgbox Route8_Text_MarcellusPostBattle, MSGBOX_AUTOCLOSE
	end

Speaker_Casey:
    .string "Casey$"

Route8_EventScript_Casey::
	trainerbattle_single TRAINER_CASEY, Route8_Text_CaseyIntro, Route8_Text_CaseyDefeat
	setspeaker Speaker_Casey
	msgbox Route8_Text_CaseyPostBattle, MSGBOX_AUTOCLOSE
	end

Speaker_Renee:
    .string "Renee$"

Route8_EventScript_Renee::
	trainerbattle_single TRAINER_RENEE, Route8_Text_ReneeIntro, Route8_Text_ReneeDefeat
	setspeaker Speaker_Renee
	msgbox Route8_Text_ReneePostBattle, MSGBOX_AUTOCLOSE
	end

Speaker_Willis:
    .string "Willis$"

Route8_EventScript_Willis::
	trainerbattle_single TRAINER_WILLIS, Route8_Text_WillisIntro, Route8_Text_WillisDefeat
	setspeaker Speaker_Willis
	msgbox Route8_Text_WillisPostBattle, MSGBOX_AUTOCLOSE
	end

Speaker_Lorie:
    .string "Lorie$"

Route8_EventScript_Lorie::
	trainerbattle_single TRAINER_LORIE, Route8_Text_LorieIntro, Route8_Text_LorieDefeat
	setspeaker Speaker_Lorie
	msgbox Route8_Text_LoriePostBattle, MSGBOX_AUTOCLOSE
	end

Speaker_Jericho:
    .string "Jericho$"

Route8_EventScript_Jericho::
	trainerbattle_single TRAINER_JERICHO, Route8_Text_JerichoIntro, Route8_Text_JerichoDefeat
	setspeaker Speaker_Jericho
	msgbox Route8_Text_JerichoPostBattle, MSGBOX_AUTOCLOSE
	end

Speaker_Don:
    .string "Don$"

Route8_EventScript_Don::
	trainerbattle_single TRAINER_DON, Route8_Text_DonIntro, Route8_Text_DonDefeat
	setspeaker Speaker_Don
	msgbox Route8_Text_DonPostBattle, MSGBOX_AUTOCLOSE
	end

Speaker_Lyle:
    .string "Lyle$"

Route8_EventScript_Lyle::
	trainerbattle_single TRAINER_LYLE, Route8_Text_LyleIntro, Route8_Text_LyleDefeat
	setspeaker Speaker_Lyle
	msgbox Route8_Text_LylePostBattle, MSGBOX_AUTOCLOSE
	end

Route8_EventScript_Boy::
	lockall
	faceplayer
	goto_if_set FLAG_ITEM_ROUTE_8_SNOWBALL, Route8_EventScript_ReceivedSnowball
	setspeaker Speaker_Boy
	msgbox Route8_Text_BoyGiveItem, MSGBOX_DEFAULT
	closemessage	
	giveitem ITEM_SNOWBALL
	setflag FLAG_ITEM_ROUTE_8_SNOWBALL
	setspeaker Speaker_Boy
	msgbox Route8_Text_BoyGoodLuck, MSGBOX_NPC
	closemessage
	releaseall
	end

Route8_EventScript_ReceivedSnowball::
	lockall
	setspeaker Speaker_Boy
	msgbox Route8_Text_BoyGoodLuck, MSGBOX_NPC
	closemessage
	releaseall
	end

Route8_Text_BoyGiveItem:
	.string "Weee I just want to play in the\n"
	.string "snow all day!\p"
	.string "Here, take this, and then you can\n"
	.string "play in the snow too!$"

Route8_Text_BoyGoodLuck:
	.string "Yay now you can play with me too!$"

Route8_EventScript_Elder::
	lockall
	setspeaker Speaker_Elder
	msgbox Route8_Text_Elder, MSGBOX_NPC
	releaseall
	end

Route8_Text_Elder:
	.string "The snow on the Route is calm, but\n"
	.string "be careful if you are going further\l"
	.string "up the mountains.\p"
	.string "A blizzard can strike at any moment\n"
	.string "without another warning.$"
	

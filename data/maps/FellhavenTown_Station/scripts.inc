FellhavenTown_Station_MapScripts::
	.byte 0

Speaker_Ranger:
    .string "Ranger$"

FellhavenTown_Station_EventScript_Intro_1::
	lockall
	playse SE_PIN
	applymovement LOCALID_FELLHAVEN_PINE, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_FELLHAVEN_PINE, Common_Movement_FaceDown
	waitmovement 0
	delay 4
	applymovement LOCALID_FELLHAVEN_BERITH, Common_Movement_FaceDown
	waitmovement 0
	setspeaker Speaker_Pine
	msgbox FellhavenTown_Station_Text_PineComeHere, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, FellhavenTown_Station_Movement_Intro_1
	waitmovement 0
	goto FellhavenTown_Station_EventScript_MainSpeech

FellhavenTown_Station_EventScript_Intro_2::
	lockall
	playse SE_PIN
	applymovement LOCALID_FELLHAVEN_PINE, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_FELLHAVEN_PINE, Common_Movement_FaceDown
	waitmovement 0
	delay 4
	applymovement LOCALID_FELLHAVEN_BERITH, Common_Movement_FaceDown
	waitmovement 0
	setspeaker Speaker_Pine
	msgbox FellhavenTown_Station_Text_PineComeHere, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, FellhavenTown_Station_Movement_Intro_2
	waitmovement 0
	goto FellhavenTown_Station_EventScript_MainSpeech

FellhavenTown_Station_EventScript_Intro_3::
	lockall
	playse SE_PIN
	applymovement LOCALID_FELLHAVEN_PINE, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_FELLHAVEN_PINE, Common_Movement_FaceDown
	waitmovement 0
	delay 4
	applymovement LOCALID_FELLHAVEN_BERITH, Common_Movement_FaceDown
	waitmovement 0
	setspeaker Speaker_Pine
	msgbox FellhavenTown_Station_Text_PineComeHere, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, FellhavenTown_Station_Movement_Intro_3
	waitmovement 0
	goto FellhavenTown_Station_EventScript_MainSpeech

FellhavenTown_Station_EventScript_Intro_4::
	lockall
	playse SE_PIN
	applymovement LOCALID_FELLHAVEN_PINE, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_FELLHAVEN_PINE, Common_Movement_FaceDown
	waitmovement 0
	delay 4
	applymovement LOCALID_FELLHAVEN_BERITH, Common_Movement_FaceDown
	waitmovement 0
	setspeaker Speaker_Pine
	msgbox FellhavenTown_Station_Text_PineComeHere, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, FellhavenTown_Station_Movement_Intro_4
	waitmovement 0
	goto FellhavenTown_Station_EventScript_MainSpeech

FellhavenTown_Station_EventScript_Intro_5::
	lockall
	playse SE_PIN
	applymovement LOCALID_FELLHAVEN_PINE, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_FELLHAVEN_PINE, Common_Movement_FaceDown
	waitmovement 0
	delay 4
	applymovement LOCALID_FELLHAVEN_BERITH, Common_Movement_FaceDown
	waitmovement 0
	setspeaker Speaker_Pine
	msgbox FellhavenTown_Station_Text_PineComeHere, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, FellhavenTown_Station_Movement_Intro_5
	waitmovement 0
	goto FellhavenTown_Station_EventScript_MainSpeech

FellhavenTown_Station_Text_PineComeHere:
	.string "Ah there you are {PLAYER}!\n"
	.string "Come over here, we must talk.$"

FellhavenTown_Station_Movement_Intro_1:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	face_up
	step_end

FellhavenTown_Station_Movement_Intro_2:
	walk_right
	walk_right
	walk_right
	walk_right
	face_up
	step_end

FellhavenTown_Station_Movement_Intro_3:
	walk_right
	walk_right
	walk_right
	face_up
	step_end

FellhavenTown_Station_Movement_Intro_4:
	walk_up
	face_up
	step_end

FellhavenTown_Station_Movement_Intro_5:
	walk_up
	walk_left
	face_up
	step_end

FellhavenTown_Station_EventScript_MainSpeech::
	setspeaker Speaker_Pine
	msgbox FellhavenTown_Station_Text_PineYouStart, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_FELLHAVEN_PINE, Common_Movement_FaceLeft
	waitmovement 0
	delay 4
	applymovement LOCALID_FELLHAVEN_BERITH, Common_Movement_FaceRight
	waitmovement 0
	setspeaker Speaker_Pine
	msgbox FellhavenTown_Station_Text_PineYourStory, MSGBOX_DEFAULT
	closemessage
	setspeaker Speaker_Berith
	msgbox FellhavenTown_Station_Text_BerithYes, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_FELLHAVEN_PINE, Common_Movement_FaceDown
	applymovement LOCALID_FELLHAVEN_BERITH, Common_Movement_FaceDown
	waitmovement 0
	setspeaker Speaker_Berith
	msgbox FellhavenTown_Station_Text_BerithStory, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_FELLHAVEN_PINE, Common_Movement_FaceLeft
	waitmovement 0
	delay 4
	applymovement LOCALID_FELLHAVEN_BERITH, Common_Movement_FaceRight
	waitmovement 0
	setspeaker Speaker_Pine
	msgbox FellhavenTown_Station_Text_PineThankYou, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_FELLHAVEN_PINE, Common_Movement_FaceDown
	applymovement LOCALID_FELLHAVEN_BERITH, Common_Movement_FaceDown
	waitmovement 0
	setspeaker Speaker_Pine
	msgbox FellhavenTown_Station_Text_PineContinuing, MSGBOX_DEFAULT
	closemessage
	setspeaker Speaker_Berith
	msgbox FellhavenTown_Station_Text_BerithSentJames, MSGBOX_DEFAULT
	closemessage
	closemessage
	applymovement LOCALID_FELLHAVEN_PINE, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	setspeaker Speaker_Pine
	msgbox FellhavenTown_Station_Text_PineReme, MSGBOX_DEFAULT
	closemessage
	setspeaker Speaker_Berith
	msgbox FellhavenTown_Station_Text_BerithFinally, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_FELLHAVEN_PINE, Common_Movement_FaceLeft
	waitmovement 0
	delay 2
	applymovement LOCALID_FELLHAVEN_BERITH, Common_Movement_FaceRight
	waitmovement 0
	setspeaker Speaker_Pine
	msgbox FellhavenTown_Station_Text_PineLeave, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_FELLHAVEN_PINE, Common_Movement_FaceDown
	applymovement LOCALID_FELLHAVEN_BERITH, Common_Movement_FaceDown
	waitmovement 0
	setspeaker Speaker_Pine
	msgbox FellhavenTown_Station_Text_PineStaySafe, MSGBOX_DEFAULT
	closemessage
	playse SE_PIN
	applymovement LOCALID_FELLHAVEN_BERITH, Common_Movement_ExclamationMark
	waitmovement 0
	setspeaker Speaker_Berith
	msgbox FellhavenTown_Station_Text_BerithTakeThis, MSGBOX_DEFAULT
	closemessage
	giveitem ITEM_TM_PROTECT
	applymovement LOCALID_FELLHAVEN_PINE, FellhavenTown_Station_Movement_PineLeave
	applymovement LOCALID_FELLHAVEN_BERITH, FellhavenTown_Station_Movement_BerithLeave
	waitmovement 0
	removeobject LOCALID_FELLHAVEN_PINE
	removeobject LOCALID_FELLHAVEN_BERITH
	setvar VAR_STORY, 17
	setflag FLAG_FELLHAVEN_PINE
	clearflag FLAG_HIDE_QUILSPRING_BERITH
	clearflag FLAG_HIDE_QUILSPRING_PINE
	releaseall
	end

FellhavenTown_Station_Text_PineYouStart:
	.string "Thank you for coming all this way! As\n"
	.string "soon as I heard what went on from James,\l"
	.string "I knew that we must meet in person.\p"
	.string "It seems there's a lot more going on\n"
	.string "here than we first thought!$"

FellhavenTown_Station_Text_PineYourStory:
	.string "Berith, I do believe that this is your\n"
	.string "story to tell!$"

FellhavenTown_Station_Text_BerithYes:
	.string "Er yes, thank you Professor.$"

FellhavenTown_Station_Text_BerithStory:
	.string "As you very well know, I am one of the\n"
	.string "leading religious figures in Serenado.\p"
	.string "However, our faith isn't quite as united\n"
	.string "as it may seem. The two that you ran\l"
	.string "into earlier are members of the Chosen,\p"
	.string "a radical faction of our faith that seek\n"
	.string "to harm and destory those that are not\l"
	.string "native to Serenado.\p"
	.string "Years ago, as a result of the conflict in\n"
	.string "Hoenn between Team Magma and Team Aqua,\p"
	.string "Groudon and Kyogre were awakened,\n"
	.string "and caused great destruction.\p"
	.string "Magma flowed through the land, seawater\n"
	.string "engulfed much of the coast, and many\l"
	.string "towns and landmarks were obliterated.\p"
	.string "Many chose to move away from Hoenn,\n"
	.string "rather than trying to endure the\l"
	.string "catastrophe that had occurred.\p"
	.string "Professor Pine tells me that this is when\n"
	.string "your family moved to Serenado as well,\l"
	.string "like many other families.\p"
	.string "While generally those that moved were\n"
	.string "accepted by the natives of Serenado,\p"
	.string "a group of those from my faith decided\n"
	.string "that they were not welcome here and did\l"
	.string "not deserve to be in Serenado.\p"
	.string "Fighting broke out between the natives\n"
	.string "of Serenado and those emigrating from\l"
	.string "the Hoenn region,\p"
	.string "until it was stopped by Pellus, who\n"
	.string "bacame the first and only Pokémon\l"
	.string "Champion of Serenado.\p"
	.string "I regretfully admit that I got swept up\n"
	.string "in the fervor of my religion at that time,\l"
	.string "but I realized I was in the wrong.\p"
	.string "I saw the anger of so many of my friends\n"
	.string "and colleagues, and acted on that,\l"
	.string "but that's not what our faith teaches.\p"
	.string "The most important tenent is the balance\n"
	.string "between people, Pokémon, and nature.\p"
	.string "The Chosen wish to destory that balance,\n"
	.string "they are incredibly dangerous to\l"
	.string "everyone in Serenado.$"

FellhavenTown_Station_Text_PineThankYou:
	.string "Thank you for sharing that Berith, and I\n"
	.string "agree completely.$"

FellhavenTown_Station_Text_PineContinuing:
	.string "While we don't know why the Chosen are\n"
	.string "showing up after years of being dormant,\l"
	.string "we think we know where they are going.\p"
	.string "James stated that when you confronted\n"
	.string "the Chosen in Erewood Grove, they\l"
	.string "mentioned a mission in a quarry.\p"
	.string "We are almost certain that they are\n"
	.string "referring to the Coalscorch Quarry\l"
	.string "in Sundara Village. We would like you\l"
	.string "go there and find out what is going on.\p"
	.string "The Sundara Gym Leader, Magnus, is the\n"
	.string "former head of the Pokémon Rangers.\p"
	.string "With his help I'm sure you can get to\n"
	.string "the bottom of what is happening.$"

FellhavenTown_Station_Text_BerithSentJames:
	.string "We also asked James and Isabel to go\n"
	.string "the Chosen headquarters in Reme City,\l"
	.string "and find out whatever they can there.\p"
	.string "I would go there myself, but I'm afraid\n"
	.string "I would arouse suspicion if I start\l"
	.string "poking around there.\p"
	.string "I have a feeling that they will be much\n"
	.string "less wary of a young, enthusiastic\l"
	.string "student like Isabel.$"

FellhavenTown_Station_Text_PineReme:
	.string "Now then!\p"
	.string "After getting in touch with Magnus in\n"
	.string "Sundara Village,\p"
	.string "I know James and Isabel would appreciate\n"
	.string "Isabel would appreciate your help in\l"
	.string "Reme City, as would we of course.\p"
	.string "And please avoid any confrontation with\n"
	.string "the Chosen, they are dangerous, and we\l"
	.string "have no idea how many of them there are.$"

FellhavenTown_Station_Text_BerithFinally:
	.string "I hate to make you do all of this work,\n"
	.string "but we will try to aid you and protect\l"
	.string "you as best as we can.\p"
	.string "Unfortunately we are needed back in\n"
	.string "Quilspring Town, so we can't go with\l"
	.string "you to Sundara Village.\p"
	.string "In our research of the runes found on\n"
	.string "Route 7, it seems like they are related\l"
	.string "to some sort of ancient myth.\p"
	.string "That must be why the Unown appeared,\n"
	.string "to get us to look at these runes,\l"
	.string "but I don't know what it is just yet.\p"
	.string "But in case this has anything to do\n"
	.string "with why the Chosen are appearing\l"
	.string "again, we need to figure it out soon.$"

FellhavenTown_Station_Text_PineLeave:
	.string "With that, we should be going Berith.$"

FellhavenTown_Station_Text_PineStaySafe:
	.string "Good luck {PLAYER}, and be careful.$"

FellhavenTown_Station_Text_BerithTakeThis:
	.string "One more thing!\p"
	.string "Please accept this, hoepfully it will\n"
	.string "help keep you safe on your travels.$"

FellhavenTown_Station_Movement_BerithLeave:
	walk_left
	walk_left
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

FellhavenTown_Station_Movement_PineLeave:
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

FellhavenTown_Station_EventScript_Man::
	lockall
	setspeaker Speaker_Ranger
	msgbox FellhavenTown_Station_Text_Man, MSGBOX_NPC
	releaseall
	end

FellhavenTown_Station_Text_Man:
	.string "It's hard work being a Pokémon\n"
	.string "Ranger, but we have a duty to\l"
	.string "Pokémon and each other.$"

FellhavenTown_Station_EventScript_Trader::
	lock
	faceplayer
	goto_if_set FLAG_FELLHAVEN_NPC_TRADE_COMPLETED, FellhavenTown_Station_EventScript_TradeCompleted
	setvar VAR_0x8008, INGAME_TRADE_CASTFORM
	copyvar VAR_0x8004, VAR_0x8008
	specialvar VAR_RESULT, GetInGameTradeSpeciesInfo
	copyvar VAR_0x8009, VAR_RESULT
	setspeaker Speaker_Ranger
	msgbox FellhavenTown_Station_Text_IllTradeIfYouWant, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, FellhavenTown_Station_EventScript_DeclineTrade
	special ChoosePartyMon
	waitstate
	copyvar VAR_0x800A, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, FellhavenTown_Station_EventScript_DeclineTrade
	copyvar VAR_0x8005, VAR_0x800A
	specialvar VAR_RESULT, GetTradeSpecies
	copyvar VAR_0x800B, VAR_RESULT
	goto_if_ne VAR_RESULT, VAR_0x8009, FellhavenTown_Station_EventScript_NotRequestedMon
	copyvar VAR_0x8004, VAR_0x8008
	copyvar VAR_0x8005, VAR_0x800A
	special CreateInGameTradePokemon
	special DoInGameTradeScene
	waitstate
	setspeaker Speaker_Ranger
	msgbox FellhavenTown_Station_Text_PleaseBeGoodToMyPokemon, MSGBOX_DEFAULT
	setflag FLAG_FELLHAVEN_NPC_TRADE_COMPLETED
	release
	end

FellhavenTown_Station_EventScript_DeclineTrade::
	setspeaker Speaker_Ranger
	msgbox FellhavenTown_Station_Text_YouDontWantToThatsOkay, MSGBOX_DEFAULT
	release
	end

FellhavenTown_Station_EventScript_NotRequestedMon::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	setspeaker Speaker_Ranger
	msgbox FellhavenTown_Station_Text_DoesntLookLikeMonToMe, MSGBOX_DEFAULT
	release
	end

FellhavenTown_Station_EventScript_TradeCompleted::
	setspeaker Speaker_Ranger
	msgbox FellhavenTown_Station_Text_AnyPokemonCanBeCute, MSGBOX_DEFAULT
	release
	end

FellhavenTown_Station_Text_IllTradeIfYouWant:
	.string "Hello! I'm supposed to deliver\n"
	.string "supplies up the mountains, but\l"
	.string "I don't have a Pokémon that can fly.\p"
	.string "Do you happen to have a {STR_VAR_1}?\n"
	.string "I really need one, they fly so well!\p"
	.string "I'll trade you my {STR_VAR_2} for\n"
	.string "a {STR_VAR_1} if you want.$"

FellhavenTown_Station_Text_PleaseBeGoodToMyPokemon:
	.string "Please be good to my Castform!$"

FellhavenTown_Station_Text_DoesntLookLikeMonToMe:
	.string "Um that doesn't look like a\n"
	.string "{STR_VAR_1} to me.$"

FellhavenTown_Station_Text_YouDontWantToThatsOkay:
	.string "Oh if you don't want to, that's okay.$"

FellhavenTown_Station_Text_AnyPokemonCanBeCute:
	.string "Every Pokémon is useful is some way,\n"
	.string "you just need to find one that fits\l"
	.string "what you need.$"

FellhavenTown_Station_EventScript_Woman::
	lockall
	setspeaker Speaker_Ranger
	msgbox FellhavenTown_Station_Text_Woman, MSGBOX_NPC
	releaseall
	end

FellhavenTown_Station_Text_Woman:
	.string "Fellhaven Town sitting at the base\n"
	.string "of the Serenado Mountains makes it\l"
	.string "the ideal place for the Ranger Station!$"

FellhavenTown_Station_EventScript_Ranger::
	lockall
	faceplayer
	setspeaker Speaker_Ranger
	msgbox FellhavenTown_Station_Text_RangerHello, MSGBOX_NPC
	closemessage
	switch VAR_RANGER_QUEST
	case 0, FellhavenTown_Station_EventScript_RangerIntro
	case 1, FellhavenTown_Station_EventScript_RangerDoYouHaveGrass
	case 2, FellhavenTown_Station_EventScript_RangerDoYouMaxFriend
	case 3, FellhavenTown_Station_EventScript_RangerDoYouHaveWyrdeer
	case 4, FellhavenTown_Station_EventScript_RangerFinal
	releaseall
	end

FellhavenTown_Station_EventScript_RangerIntro::
	setspeaker Speaker_Ranger
	msgbox FellhavenTown_Station_Text_RangerIntro, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, FellhavenTown_Station_EventScript_RangerPerfect
	setspeaker Speaker_Ranger
	msgbox FellhavenTown_Station_Text_RangerNo, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

FellhavenTown_Station_Text_RangerHello:
	.string "Ah hello!$"

FellhavenTown_Station_Text_RangerIntro:
	.string "Welcome young Trainer! We are\n"
	.string "looking for new recruits to join\l"
	.string "the Pokémon Ranger training program!\p"
	.string "Would you like to join?$"

FellhavenTown_Station_Text_RangerNo:
	.string "Oh, okay then. Come back when you're\n"
	.string "interested, we are always looking to\l"
	.string "recruit talented young Trainers!$"

FellhavenTown_Station_EventScript_RangerPerfect::
	setspeaker Speaker_Ranger
	msgbox FellhavenTown_Station_Text_RangerPerfect, MSGBOX_DEFAULT
	closemessage
	setvar VAR_RANGER_QUEST, 1
	releaseall
	end

FellhavenTown_Station_Text_RangerPerfect:
	.string "Great, so happy to hear that!\n"
	.string "Welcome to the Pokémon Rangers!\p"
	.string "For your first training excercise,\n"
	.string "please show me a Grass type Pokémon.\p"
	.string "Grass types are quite in tune with\n"
	.string "nature, they make perfect partners\l"
	.string "for any aspiring Ranger.\p"
	.string "Show me a Grass type and you'll have\n"
	.string "passed the first training excercise!$"

FellhavenTown_Station_EventScript_RangerDoYouHaveGrass::
	setspeaker Speaker_Ranger
	msgbox FellhavenTown_Station_Text_RangerDoYouHaveGrass, MSGBOX_DEFAULT
	closemessage
	special IsGrassTypeInParty
	goto_if_eq VAR_RESULT, TRUE, FellhavenTown_Station_EventScript_YesGrass
	setspeaker Speaker_Ranger
	msgbox FellhavenTown_Station_Text_RangerNoGrass, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

FellhavenTown_Station_Text_RangerDoYouHaveGrass:
	.string "Have you brought a Grass type Pokémon\n"
	.string "with you?$"

FellhavenTown_Station_Text_RangerNoGrass:
	.string "Hmm no, it doesn't seem like any of\n"
	.string "these Pokémon are of the Grass type.$"

FellhavenTown_Station_EventScript_YesGrass::
	setspeaker Speaker_Ranger
	msgbox FellhavenTown_Station_Text_RangerYesGrass, MSGBOX_DEFAULT
	closemessage
	giveitem ITEM_QUICK_CLAW
	setspeaker Speaker_Ranger
	msgbox FellhavenTown_Station_Text_RangerMission2, MSGBOX_DEFAULT
	closemessage
	setvar VAR_RANGER_QUEST, 2
	releaseall
	end

FellhavenTown_Station_Text_RangerYesGrass:
	.string "Yes that is a Grass type Pokémon!\n"
	.string "You've completed the first training\l"
	.string "excercise, nicely done!\p"
	.string "As a reward, please accept this\n"
	.string "Quick Claw!$"

FellhavenTown_Station_Text_RangerMission2:
	.string "Now, to be a true Pokémon Ranger\n"
	.string "you have to have a strong connection\l"
	.string "with your Pokémon.\p"
	.string "So for your second training excercise,\n"
	.string "show me a Pokémon that you have a strong\l"
	.string "bond with, one with high friendship.$"

FellhavenTown_Station_EventScript_RangerDoYouMaxFriend::
	setspeaker Speaker_Ranger
	msgbox FellhavenTown_Station_Text_RangerDoYouMaxFriend, MSGBOX_DEFAULT
	closemessage
	specialvar VAR_RESULT, GetLeadMonFriendshipScore
	switch VAR_RESULT
	case FRIENDSHIP_NONE, FellhavenTown_Station_EventScript_NoFriend
	case FRIENDSHIP_1_TO_49, FellhavenTown_Station_EventScript_NoFriend
	case FRIENDSHIP_50_TO_99, FellhavenTown_Station_EventScript_NoFriend
	case FRIENDSHIP_100_TO_149, FellhavenTown_Station_EventScript_NoFriend
	case FRIENDSHIP_150_TO_199, FellhavenTown_Station_EventScript_NoFriend
	case FRIENDSHIP_200_TO_254, FellhavenTown_Station_EventScript_YesFriend
	case FRIENDSHIP_MAX, FellhavenTown_Station_EventScript_YesFriend
	releaseall
	end

FellhavenTown_Station_Text_RangerDoYouMaxFriend:
	.string "Let me check the friendship of your\n"
	.string "lead Pokémon.$"

FellhavenTown_Station_EventScript_NoFriend::
	setspeaker Speaker_Ranger
	msgbox FellhavenTown_Station_Text_RangerNotFriend, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

FellhavenTown_Station_Text_RangerNotFriend:
	.string "Hmm no, it doesn't seem like you have\n"
	.string "truly bonded with this Pokémon yet.$"

FellhavenTown_Station_EventScript_YesFriend::
	setspeaker Speaker_Ranger
	msgbox FellhavenTown_Station_Text_RangerYesFriend, MSGBOX_DEFAULT
	closemessage
	giveitem ITEM_SAFETY_GOGGLES
	setspeaker Speaker_Ranger
	msgbox FellhavenTown_Station_Text_RangerMission3, MSGBOX_DEFAULT
	closemessage
	setvar VAR_RANGER_QUEST, 3
	releaseall
	end

FellhavenTown_Station_Text_RangerYesFriend:
	.string "Ohh I can tell that you have really\n"
	.string "bonded with that Pokémon, it considers\l"
	.string "you a true friend.\p"
	.string "As a reward, please accept these\n"
	.string "Safety Goggles!$"

FellhavenTown_Station_Text_RangerMission3:
	.string "You are doing great! But this final\n"
	.string "training excercise will be a tough\l"
	.string "challenge for sure.\p"
	.string "Since we are located at the base of the\n"
	.string "Serenado Mountains, us Rangers consider\l"
	.string "ourselves the protectors of mountains.\p"
	.string "But there is a Pokémon that guards these\n"
	.string "mountains, the big horn Pokémon Wyrdeer.\p"
	.string "While they are incredibly rare to find,\n"
	.string "show me this Pokémon to complete the\l"
	.string "final challenge.$"

FellhavenTown_Station_EventScript_RangerDoYouHaveWyrdeer::
	setspeaker Speaker_Ranger
	msgbox FellhavenTown_Station_Text_RangerDoYouHaveWyrdeer, MSGBOX_DEFAULT
	closemessage
	special IsWyrdeerInParty
	goto_if_eq VAR_RESULT, TRUE, FellhavenTown_Station_EventScript_YesWyrdeer
	setspeaker Speaker_Ranger
	msgbox FellhavenTown_Station_Text_RangerNoWyrdeer, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

FellhavenTown_Station_Text_RangerDoYouHaveWyrdeer:
	.string "Have you found the Pokémon that\n"
	.string "guards the mountains, Wyrdeer?$"

FellhavenTown_Station_Text_RangerNoWyrdeer:
	.string "Hmm no, you don't seem to have\n"
	.string "Wyrdeer in your party.$"

FellhavenTown_Station_EventScript_YesWyrdeer::
	setspeaker Speaker_Ranger
	msgbox FellhavenTown_Station_Text_RangerYesWyrdeer, MSGBOX_DEFAULT
	closemessage
	giveitem ITEM_HEAVY_DUTY_BOOTS
	goto FellhavenTown_Station_EventScript_RangerFinal
	releaseall
	end

FellhavenTown_Station_EventScript_RangerFinal::
	setspeaker Speaker_Ranger
	msgbox FellhavenTown_Station_Text_RangerFinal, MSGBOX_DEFAULT
	closemessage
	setvar VAR_RANGER_QUEST, 4
	releaseall
	end

FellhavenTown_Station_Text_RangerYesWyrdeer:
	.string "Woah that really is a Wyrdeer! I have\n"
	.string "only seen those in the wild, never in\l"
	.string "the party of a Trainer!\p"
	.string "Here is your reward for completing the\n"
	.string "Pokémon Ranger training program!$"

FellhavenTown_Station_Text_RangerFinal:
	.string "You definitely have the skills to be a\n"
	.string "great Pokémon Ranger one day!\p"
	.string "And with the gear you've received as\n"
	.string "rewards for the training excercises,\l"
	.string "you're all ready for the mountians!\p"
	.string "Good luck!$"











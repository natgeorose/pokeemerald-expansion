FellhavenTown_MapScripts::
	.byte 0

FellhavenTown_EventScript_TownSign::
	msgbox FellhavenTown_Text_TownSign, MSGBOX_SIGN
	end

FellhavenTown_Text_TownSign:
	.string "Fellhaven Town\n"
	.string "“Where snowy peaks meet warm hearts.”$"

FellhavenTown_EventScript_TutorSign::
	msgbox FellhavenTown_Text_TutorSign, MSGBOX_SIGN
	end

FellhavenTown_Text_TutorSign:
	.string "Fellhaven Town Move Tutor$"

FellhavenTown_EventScript_HerbSign::
	msgbox FellhavenTown_Text_HerbSign, MSGBOX_SIGN
	end

FellhavenTown_Text_HerbSign:
	.string "Fellhaven Town Herbal Medicine Shop$"

FellhavenTown_EventScript_RangerSign::
	msgbox FellhavenTown_Text_RangerSign, MSGBOX_SIGN
	end

FellhavenTown_Text_RangerSign:
	.string "Fellhaven Town Pokémon Ranger Station$"


FellhavenTown_EventScript_Woman::
	lockall
	setspeaker Speaker_Woman
	msgbox FellhavenTown_Text_Woman, MSGBOX_NPC
	releaseall
	end

FellhavenTown_Text_Woman:
	.string "Fellhaven Town sits at the base of the\n"
	.string "Serenado Mountains. I want to climb\l"
	.string "them some day!$"

FellhavenTown_EventScript_Man::
	lockall
	setspeaker Speaker_Man
	msgbox FellhavenTown_Text_Man, MSGBOX_NPC
	releaseall
	end

FellhavenTown_Text_Man:
	.string "The Pokémon Rangers have their base\n"
	.string "here in Fellhaven Town. I always\l"
	.string "wanted to be one when growing up.$"

FellhavenTown_EventScript_FlowerWoman::
	lockall
	setspeaker Speaker_Woman
	msgbox FellhavenTown_Text_FlowerWoman, MSGBOX_NPC
	releaseall
	end

FellhavenTown_Text_FlowerWoman:
	.string "These yellow flowers are unique to\n"
	.string "the mountains. I find them so pretty!$"

FellhavenTown_EventScript_James::
	lockall
	goto_if_eq VAR_STORY, 16, FellhavenTown_EventScript_JamesPre
	setspeaker Speaker_James
	msgbox FellhavenTown_Text_James, MSGBOX_NPC
	releaseall
	end

FellhavenTown_Text_James:
	.string "You talked to the Professor?\p"
	.string "Oh he wants you to go up to\n"
	.string "Coalscorch Quarry? Wow that's\l"
	.string "far away, good luck!$"

FellhavenTown_EventScript_JamesPre::
	setspeaker Speaker_James
	msgbox FellhavenTown_Text_JamesPre, MSGBOX_NPC
	closemessage
	releaseall
	end

FellhavenTown_Text_JamesPre:
	.string "Good to see you {PLAYER}!\p"
	.string "We already talked to the Professor,\n"
	.string "we've got a special mission up in\l"
	.string "Reme City, past Route 8.$"

FellhavenTown_EventScript_Isabel::
	lockall
	setspeaker Speaker_Isabel
	msgbox FellhavenTown_Text_Isabel, MSGBOX_NPC
	releaseall
	end

FellhavenTown_Text_Isabel:
	.string "Hi {PLAYER}! We've made some good\n"
	.string "progress on deciphering those\l"
	.string "ancient runes, it's fascinating!$"

FellhavenTown_EventScript_StopTop::
	lockall
	goto_if_eq VAR_STORY, 16, FellhavenTown_EventScript_StopTopPre
	goto_if_le VAR_STORY, 19, FellhavenTown_EventScript_StopTopPost
	releaseall
	end

FellhavenTown_EventScript_StopTopPre::
	playse SE_PIN
	applymovement LOCALID_FELLHAVEN_JAMES, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_FELLHAVEN_JAMES, Common_Movement_FaceUp
	waitmovement 0
	setspeaker Speaker_James
	msgbox FellhavenTown_Text_JamesTalkToProfessor, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_FELLHAVEN_JAMES, Common_Movement_FaceDown
	applymovement LOCALID_PLAYER, Common_Movement_WalkLeft
	waitmovement 0
	releaseall
	end

FellhavenTown_EventScript_StopTopPost::
	playse SE_PIN
	applymovement LOCALID_FELLHAVEN_JAMES, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_FELLHAVEN_JAMES, Common_Movement_FaceUp
	waitmovement 0
	setspeaker Speaker_James
	msgbox FellhavenTown_Text_JamesWeGotThis, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_FELLHAVEN_JAMES, Common_Movement_FaceDown
	applymovement LOCALID_PLAYER, Common_Movement_WalkLeft
	waitmovement 0
	releaseall
	end

FellhavenTown_EventScript_StopBottom::
	lockall
	goto_if_eq VAR_STORY, 16, FellhavenTown_EventScript_StopBottomPre
	goto_if_le VAR_STORY, 19, FellhavenTown_EventScript_StopBottomPost
	releaseall
	end

FellhavenTown_EventScript_StopBottomPre::
	playse SE_PIN
	applymovement LOCALID_FELLHAVEN_JAMES, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_FELLHAVEN_JAMES, Common_Movement_FaceDown
	waitmovement 0
	setspeaker Speaker_James
	msgbox FellhavenTown_Text_JamesTalkToProfessor, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, Common_Movement_WalkLeft
	waitmovement 0
	releaseall
	end

FellhavenTown_EventScript_StopBottomPost::
	playse SE_PIN
	applymovement LOCALID_FELLHAVEN_JAMES, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_FELLHAVEN_JAMES, Common_Movement_FaceDown
	waitmovement 0
	setspeaker Speaker_James
	msgbox FellhavenTown_Text_JamesWeGotThis, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, Common_Movement_WalkLeft
	waitmovement 0
	releaseall
	end

FellhavenTown_Text_JamesTalkToProfessor:
	.string "Hey, you should talk to the\n"
	.string "Professor before going this way!$"

FellhavenTown_Text_JamesWeGotThis:
	.string "We've got things over this way,\n"
	.string "you should head up to the quarry!$"








	

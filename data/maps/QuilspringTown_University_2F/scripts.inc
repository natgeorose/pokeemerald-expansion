QuilspringTown_University_2F_MapScripts::
	.byte 0

QuilspringTown_University_2F_EventScript_Girl::
	lockall
	setspeaker Speaker_Girl
	msgbox QuilspringTown_University_2F_Text_Girl, MSGBOX_NPC
	releaseall
	end

QuilspringTown_University_2F_Text_Girl:
	.string "Where is the lecturer? I have\n"
	.string "so many questions about class!$"

QuilspringTown_University_2F_EventScript_Berith::
	lockall
	faceplayer
	goto_if_set FLAG_ITEM_QUILSPRING_CARBOS, QuilspringTown_University_2F_EventScript_ReceivedCarbos
	setspeaker Speaker_Berith
	msgbox QuilspringTown_University_2F_Text_BerithGiveItem, MSGBOX_DEFAULT
	closemessage	
	giveitem ITEM_CARBOS
	setspeaker Speaker_Berith
	msgbox QuilspringTown_University_2F_Text_BerithGoodLuck, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_ITEM_QUILSPRING_CARBOS
	releaseall
	end

QuilspringTown_University_2F_EventScript_ReceivedCarbos::
	lockall
	setspeaker Speaker_Berith
	msgbox QuilspringTown_University_2F_Text_BerithGoodLuck, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

QuilspringTown_University_2F_Text_BerithGiveItem:
	.string "Good to see you {PLAYER}!\p"
	.string "We've been doing a lot of research\n"
	.string "about the ancient runes that you\l"
	.string "discovered in that cave.\p"
	.string "I realize that I was so excited\n"
	.string "that I never properly thanked you\l"
	.string "for leading us to that cave.\p"
	.string "Please take this Carbos as a sign\n"
	.string "of my gratitude, it is a very\l"
	.string "rare item in Serenado.$"

QuilspringTown_University_2F_Text_BerithGoodLuck:
	.string "Good luck on your adventure!\n"
	.string "I hope to see you again.$"





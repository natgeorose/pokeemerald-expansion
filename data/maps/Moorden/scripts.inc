Moorden_MapScripts::
	.byte 0

Speaker_Fashionista:
    .string "Fashionista$"

Moorden_EventScript_Fashionista::
	lockall
	faceplayer
	goto_if_set FLAG_RECEIVED_SILK_SCARF, Moorden_EventScript_ReceivedScarf
	setspeaker Speaker_Fashionista
	msgbox Moorden_Text_FashionistaGiveItem, MSGBOX_DEFAULT
	closemessage	
	giveitem ITEM_SILK_SCARF
	setspeaker Speaker_Fashionista
	msgbox Moorden_Text_FashionistaGoodLuck, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_RECEIVED_SILK_SCARF
	releaseall
	end

Moorden_EventScript_ReceivedScarf::
	lockall
	setspeaker Speaker_Fashionista
	msgbox Moorden_Text_FashionistaGoodLuck, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

Moorden_Text_FashionistaGiveItem:
	.string "Ah, what is this thing that you\n"
	.string "are wearing?! It's just dreadful!\p"
	.string "I can't believe you somehow left\n"
	.string "your home looking like this!\p"
	.string "Quickly, take this! You can use it\n"
	.string "to cover up at least some of that\l"
	.string "awful outfit you have on.$"

Moorden_Text_FashionistaGoodLuck:
	.string "That's a little better, please go\n"
	.string "change for everybody's sake!$"

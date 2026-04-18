SundaraVillage_House2_MapScripts::
	.byte 0

Speaker_CoolGuy:
    .string "Cool Guy$"

SundaraVillage_House2_EventScript_CoolGuy::
	lockall
	faceplayer
	goto_if_set FLAG_ITEM_BLACK_GLASSES, SundaraVillage_House2_EventScript_ReceivedBlackGlasses
	setspeaker Speaker_CoolGuy
	msgbox SundaraVillage_House2_Text_CoolGuyGiveItem, MSGBOX_DEFAULT
	closemessage	
	giveitem ITEM_BLACK_GLASSES
	setspeaker Speaker_CoolGuy
	msgbox SundaraVillage_House2_Text_CoolGuyGoodLuck, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_ITEM_BLACK_GLASSES
	releaseall
	end

SundaraVillage_House2_EventScript_ReceivedBlackGlasses::
	lockall
	setspeaker Speaker_CoolGuy
	msgbox SundaraVillage_House2_Text_CoolGuyGoodLuck, MSGBOX_NPC
	closemessage
	releaseall
	end

SundaraVillage_House2_Text_CoolGuyGiveItem:
	.string "It's way too hot, I don't know why I\n"
	.string "live in a place like Sundara Village.\p"
	.string "Even if I have a hard time staying\n"
	.string "cool, I still look cool thanks to\l"
	.string "these Black Glasses.\p"
	.string "Here, you can have some as well. It's\n"
	.string "almost as good as actually being cool.$"

SundaraVillage_House2_Text_CoolGuyGoodLuck:
	.string "Hmm yes, you already look cooler.$"



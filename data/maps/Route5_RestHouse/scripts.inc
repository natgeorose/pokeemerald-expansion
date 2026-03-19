Route5_RestHouse_MapScripts::
	.byte 0

Route5_RestHouse_EventScript_Woman::
	lockall
	setspeaker Speaker_Elder
	msgbox Route5_RestHouse_Text_Woman, MSGBOX_NPC
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	releaseall
	end

Route5_RestHouse_Text_Woman:
	.string "Hello there! You seem tired, you\n"
	.string "and your Pokémon should rest.$"

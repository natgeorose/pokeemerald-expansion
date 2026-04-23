FellhavenTown_House_3_MapScripts::
	.byte 0

FellhavenTown_House_3_EventScript_Man::
	lockall
	setspeaker Speaker_Man
	msgbox FellhavenTown_House_3_Text_Man, MSGBOX_NPC
	releaseall
	end

FellhavenTown_House_3_Text_Man:
	.string "I'm thinking of opening a ski resort\n"
	.string "on Route 8. I'm sure it will make me\l"
	.string "a lot of money.$"




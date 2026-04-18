 SundaraVillage_House3_MapScripts::
	.byte 0


SundaraVillage_House3_EventScript_ExpertM::
	lockall
	setspeaker Speaker_Elder
	msgbox SundaraVillage_House3_Text_ExpertM, MSGBOX_NPC
	releaseall
	end

SundaraVillage_House3_Text_ExpertM:
	.string "It's hot in Sundara Village, but my\n"
	.string "old bones love the sun.$"

SundaraVillage_House3_EventScript_ExpertF::
	lockall
	setspeaker Speaker_Elder
	msgbox SundaraVillage_House3_Text_ExpertF, MSGBOX_NPC
	releaseall
	end

SundaraVillage_House3_Text_ExpertF:
	.string "Our tiny village here is mostly\n"
	.string "made up of those who work in\l"
	.string "Coalscorch Quarry.$"

#include "oamlGodotModule.h"

void oamlGodotModule::Init(String defsFilename) {
	oaml->Init(defsFilename.ascii().get_data());
}

void oamlGodotModule::InitString(String defs) {
	oaml->InitString(defs.ascii());
}

void oamlGodotModule::InitAudioDevice() {
	oaml->InitAudioDevice();
}

void oamlGodotModule::Pause() {
	oaml->Pause();
}

void oamlGodotModule::PlayTrack(String name) {
	oaml->PlayTrack(name.ascii());
}

void oamlGodotModule::PlayTrackWithStringRandom(String str) {
	oaml->PlayTrackWithStringRandom(str.ascii());
}

void oamlGodotModule::PlayTrackByGroupRandom(String group) {
	oaml->PlayTrackByGroupRandom(group.ascii());
}

void oamlGodotModule::PlayTrackByGroupAndSubgroupRandom(String group, String subgroup) {
	oaml->PlayTrackByGroupAndSubgroupRandom(group.ascii(), subgroup.ascii());
}

void oamlGodotModule::Resume() {
	oaml->Resume();
}

void oamlGodotModule::SetMainLoopCondition(int value) {
	oaml->SetMainLoopCondition(value);
}

void oamlGodotModule::SetCondition(int id, int value) {
	oaml->SetCondition(id, value);
}

void oamlGodotModule::_bind_methods() {
	ObjectTypeDB::bind_method("Init", &oamlGodotModule::Init);
	ObjectTypeDB::bind_method("InitString", &oamlGodotModule::InitString);
	ObjectTypeDB::bind_method("InitAudioDevice", &oamlGodotModule::InitAudioDevice);
	ObjectTypeDB::bind_method("Pause", &oamlGodotModule::Pause);
	ObjectTypeDB::bind_method("PlayTrack", &oamlGodotModule::PlayTrack);
	ObjectTypeDB::bind_method("PlayTrackWithStringRandom", &oamlGodotModule::PlayTrackWithStringRandom);
	ObjectTypeDB::bind_method("PlayTrackByGroupRandom", &oamlGodotModule::PlayTrackByGroupRandom);
	ObjectTypeDB::bind_method("PlayTrackByGroupAndSubgroupRandom", &oamlGodotModule::PlayTrackByGroupAndSubgroupRandom);
	ObjectTypeDB::bind_method("Resume", &oamlGodotModule::Resume);
	ObjectTypeDB::bind_method("SetMainLoopCondition", &oamlGodotModule::SetMainLoopCondition);
	ObjectTypeDB::bind_method("SetCondition", &oamlGodotModule::SetCondition);
}

oamlGodotModule::oamlGodotModule() {
	oaml = new oamlApi();
}

#include "oamlGodotModule.h"

void oamlGodotModule::Init(String defsFilename) {
	oaml->Init(defsFilename.ascii().get_data());
}

void oamlGodotModule::InitAudioDevice() {
	oaml->InitAudioDevice();
}

void oamlGodotModule::PlayTrack(String name) {
	oaml->PlayTrack(name.ascii());
}

void oamlGodotModule::SetMainLoopCondition(int value) {
	oaml->SetMainLoopCondition(value);
}

void oamlGodotModule::SetCondition(int id, int value) {
	oaml->SetCondition(id, value);
}

void oamlGodotModule::_bind_methods() {
	ObjectTypeDB::bind_method("Init", &oamlGodotModule::Init);
	ObjectTypeDB::bind_method("InitAudioDevice", &oamlGodotModule::InitAudioDevice);
	ObjectTypeDB::bind_method("PlayTrack", &oamlGodotModule::PlayTrack);
	ObjectTypeDB::bind_method("SetMainLoopCondition", &oamlGodotModule::SetMainLoopCondition);
	ObjectTypeDB::bind_method("SetCondition", &oamlGodotModule::SetCondition);
}

oamlGodotModule::oamlGodotModule() {
	oaml = new oamlApi();
}

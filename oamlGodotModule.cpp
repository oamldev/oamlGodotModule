#include "os/file_access.h"

#include "oamlGodotModule.h"

void oamlGodotModule::AddTension(int value) {
	oaml->AddTension(value);
}

void oamlGodotModule::EnableDynamicCompressor(bool enable, double thresholdDb, double ratio) {
	oaml->EnableDynamicCompressor(enable, thresholdDb, ratio);
}

String oamlGodotModule::GetPlayingInfo() {
	return String(oaml->GetPlayingInfo());
}

float oamlGodotModule::GetVolume() {
	return oaml->GetVolume();
}

void oamlGodotModule::Init(String defsFilename) {
	oaml->Init(defsFilename.ascii().get_data());
}

void oamlGodotModule::InitString(String defs) {
	oaml->InitString(defs.ascii());
}

void oamlGodotModule::InitAudioDevice() {
	oaml->InitAudioDevice();
}

bool oamlGodotModule::IsPaused() {
	return oaml->IsPaused();
}

bool oamlGodotModule::IsPlaying() {
	return oaml->IsPlaying();
}

bool oamlGodotModule::IsTrackPlaying(String name) {
	return oaml->IsTrackPlaying(name.ascii());
}

void oamlGodotModule::LoadTrack(String name) {
	oaml->LoadTrack(name.ascii());
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

void oamlGodotModule::SetLayerGain(String layer, float gain) {
	oaml->SetLayerGain(layer.ascii(), gain);
}

void oamlGodotModule::SetLayerRandomChance(String layer, int randomChance) {
	oaml->SetLayerRandomChance(layer.ascii(), randomChance);
}

void oamlGodotModule::SetTension(int value) {
	oaml->SetTension(value);
}

void oamlGodotModule::SetVolume(float value) {
	oaml->SetVolume(value);
}

void oamlGodotModule::StopPlaying() {
	oaml->StopPlaying();
}

void oamlGodotModule::_bind_methods() {
	ObjectTypeDB::bind_method("AddTension", &oamlGodotModule::AddTension);
	ObjectTypeDB::bind_method("EnableDynamicCompressor", &oamlGodotModule::EnableDynamicCompressor);
	ObjectTypeDB::bind_method("GetPlayingInfo", &oamlGodotModule::GetPlayingInfo);
	ObjectTypeDB::bind_method("GetVolume", &oamlGodotModule::GetVolume);
	ObjectTypeDB::bind_method("Init", &oamlGodotModule::Init);
	ObjectTypeDB::bind_method("InitString", &oamlGodotModule::InitString);
	ObjectTypeDB::bind_method("InitAudioDevice", &oamlGodotModule::InitAudioDevice);
	ObjectTypeDB::bind_method("IsPaused", &oamlGodotModule::IsPaused);
	ObjectTypeDB::bind_method("IsPlaying", &oamlGodotModule::IsPlaying);
	ObjectTypeDB::bind_method("IsTrackPlaying", &oamlGodotModule::IsTrackPlaying);
	ObjectTypeDB::bind_method("LoadTrack", &oamlGodotModule::LoadTrack);
	ObjectTypeDB::bind_method("Pause", &oamlGodotModule::Pause);
	ObjectTypeDB::bind_method("PlayTrack", &oamlGodotModule::PlayTrack);
	ObjectTypeDB::bind_method("PlayTrackWithStringRandom", &oamlGodotModule::PlayTrackWithStringRandom);
	ObjectTypeDB::bind_method("PlayTrackByGroupRandom", &oamlGodotModule::PlayTrackByGroupRandom);
	ObjectTypeDB::bind_method("PlayTrackByGroupAndSubgroupRandom", &oamlGodotModule::PlayTrackByGroupAndSubgroupRandom);
	ObjectTypeDB::bind_method("Resume", &oamlGodotModule::Resume);
	ObjectTypeDB::bind_method("SetMainLoopCondition", &oamlGodotModule::SetMainLoopCondition);
	ObjectTypeDB::bind_method("SetCondition", &oamlGodotModule::SetCondition);
	ObjectTypeDB::bind_method("SetLayerGain", &oamlGodotModule::SetLayerGain);
	ObjectTypeDB::bind_method("SetLayerRandomChance", &oamlGodotModule::SetLayerRandomChance);
	ObjectTypeDB::bind_method("SetTension", &oamlGodotModule::SetTension);
	ObjectTypeDB::bind_method("SetVolume", &oamlGodotModule::SetVolume);
	ObjectTypeDB::bind_method("StopPlaying", &oamlGodotModule::StopPlaying);
}

static void* oamlOpen(const char *filename) {
	FileAccess *f = FileAccess::open("res://"+String(filename), FileAccess::READ);
	if (f == NULL) {
		return NULL;
	}
	return (void*)f;
}

static size_t oamlRead(void *ptr, size_t size, size_t nitems, void *fd) {
	FileAccess *f = (FileAccess*)fd;
	return f->get_buffer((uint8_t*)ptr, size*nitems);
}

static int oamlSeek(void *fd, long offset, int whence) {
	FileAccess *f = (FileAccess*)fd;
	if (whence == SEEK_SET)
		f->seek(offset);
	else if (whence == SEEK_END)
		f->seek_end(offset);
	else if (whence == SEEK_CUR)
		f->seek(f->get_pos()+offset);
	return 0;
}

static long oamlTell(void *fd) {
	FileAccess *f = (FileAccess*)fd;
	return f->get_pos();
}

static int oamlClose(void *fd) {
	FileAccess *f = (FileAccess*)fd;
	f->close();
	memdelete(f);
	return 0;
}

static oamlFileCallbacks fileCbs = {
	&oamlOpen,
	&oamlRead,
	&oamlSeek,
	&oamlTell,
	&oamlClose
};


oamlGodotModule::oamlGodotModule() {
	oaml = new oamlApi();
	oaml->SetFileCallbacks(&fileCbs);
}

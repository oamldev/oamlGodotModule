#include "os/file_access.h"

#include "oamlGodotModule.h"


int oamlGodotModule::InternalStream::get_channel_count() const {
	return 2;
}

void oamlGodotModule::InternalStream::set_mix_rate(int p_rate) {
	owner->set_mix_rate(p_rate);
}

void oamlGodotModule::InternalStream::update() {
}

bool oamlGodotModule::InternalStream::mix(int32_t *p_buffer, int p_frames) {
	return owner->mix(p_buffer, p_frames);
}

void oamlGodotModule::set_mix_rate(int p_rate) {
	if (oaml == NULL)
		return;

	oaml->SetAudioFormat(p_rate, 2, 4, false);
}

bool oamlGodotModule::mix(int32_t *p_buffer, int p_frames) {
	if (oaml == NULL)
		return true;

	zeromem(p_buffer, p_frames*sizeof(int32_t)*2);
	oaml->MixToBuffer(p_buffer, p_frames*2);

	return true;
}

void oamlGodotModule::AddTension(int value) {
	if (oaml == NULL)
		return;

	oaml->AddTension(value);
}

void oamlGodotModule::EnableDynamicCompressor(bool enable, double thresholdDb, double ratio) {
	if (oaml == NULL)
		return;

	oaml->EnableDynamicCompressor(enable, thresholdDb, ratio);
}

String oamlGodotModule::GetPlayingInfo() {
	if (oaml == NULL)
		return "";

	return String(oaml->GetPlayingInfo());
}

float oamlGodotModule::GetVolume() {
	if (oaml == NULL)
		return 1.0f;

	return oaml->GetVolume();
}

void oamlGodotModule::Init(String defsFilename) {
	if (oaml == NULL)
		return;

	oaml->Init(defsFilename.ascii().get_data());
}

void oamlGodotModule::InitString(String defs) {
	if (oaml == NULL)
		return;

	oaml->InitString(defs.ascii());
}

bool oamlGodotModule::IsPaused() {
	if (oaml == NULL)
		return true;

	return oaml->IsPaused();
}

bool oamlGodotModule::IsPlaying() {
	if (oaml == NULL)
		return false;

	return oaml->IsPlaying();
}

bool oamlGodotModule::IsTrackPlaying(String name) {
	if (oaml == NULL)
		return false;

	return oaml->IsTrackPlaying(name.ascii());
}

void oamlGodotModule::LoadTrack(String name) {
	if (oaml == NULL)
		return;

	oaml->LoadTrack(name.ascii());
}

void oamlGodotModule::Pause() {
	if (oaml == NULL)
		return;

	oaml->Pause();
}

void oamlGodotModule::PlayTrack(String name) {
	if (oaml == NULL)
		return;

	oaml->PlayTrack(name.ascii());
}

void oamlGodotModule::PlayTrackWithStringRandom(String str) {
	if (oaml == NULL)
		return;

	oaml->PlayTrackWithStringRandom(str.ascii());
}

void oamlGodotModule::PlayTrackByGroupRandom(String group) {
	if (oaml == NULL)
		return;

	oaml->PlayTrackByGroupRandom(group.ascii());
}

void oamlGodotModule::PlayTrackByGroupAndSubgroupRandom(String group, String subgroup) {
	if (oaml == NULL)
		return;

	oaml->PlayTrackByGroupAndSubgroupRandom(group.ascii(), subgroup.ascii());
}

void oamlGodotModule::Resume() {
	if (oaml == NULL)
		return;

	oaml->Resume();
}

void oamlGodotModule::SetMainLoopCondition(int value) {
	if (oaml == NULL)
		return;

	oaml->SetMainLoopCondition(value);
}

void oamlGodotModule::SetCondition(int id, int value) {
	if (oaml == NULL)
		return;

	oaml->SetCondition(id, value);
}

void oamlGodotModule::SetLayerGain(String layer, float gain) {
	if (oaml == NULL)
		return;

	oaml->SetLayerGain(layer.ascii(), gain);
}

void oamlGodotModule::SetLayerRandomChance(String layer, int randomChance) {
	if (oaml == NULL)
		return;

	oaml->SetLayerRandomChance(layer.ascii(), randomChance);
}

void oamlGodotModule::SetTension(int value) {
	if (oaml == NULL)
		return;

	oaml->SetTension(value);
}

void oamlGodotModule::SetVolume(float value) {
	if (oaml == NULL)
		return;

	oaml->SetVolume(value);
}

void oamlGodotModule::StopPlaying() {
	if (oaml == NULL)
		return;

	oaml->StopPlaying();
}

void oamlGodotModule::_bind_methods() {
	ObjectTypeDB::bind_method("AddTension", &oamlGodotModule::AddTension);
	ObjectTypeDB::bind_method("EnableDynamicCompressor", &oamlGodotModule::EnableDynamicCompressor);
	ObjectTypeDB::bind_method("GetPlayingInfo", &oamlGodotModule::GetPlayingInfo);
	ObjectTypeDB::bind_method("GetVolume", &oamlGodotModule::GetVolume);
	ObjectTypeDB::bind_method("Init", &oamlGodotModule::Init);
	ObjectTypeDB::bind_method("InitString", &oamlGodotModule::InitString);
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
		print_line("oaml: Error opening resource file: res://"+String(filename));
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
	oaml->SetAudioFormat(44100, 2, 4, false);

	stream = memnew(InternalStream);
	stream->owner = this;
	streamRid = AudioServer::get_singleton()->audio_stream_create(stream);
	AudioServer::get_singleton()->stream_set_active(streamRid, true);
}

oamlGodotModule::~oamlGodotModule() {
	if (oaml != NULL) {
		oaml->Shutdown();
		delete oaml;
	}

	AudioServer::get_singleton()->free(streamRid);
}

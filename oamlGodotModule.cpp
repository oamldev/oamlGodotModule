#include "os/file_access.h"

#include "oamlGodotModule.h"


void oamlGodotModule::set_mix_rate(int p_rate) {
	if (oaml == NULL)
		return;

	oaml->SetAudioFormat(p_rate, 2, 4, true);
}

bool oamlGodotModule::mix(AudioFrame *p_buffer, int p_frames) {

	if (oaml == NULL)
		return true;

	zeromem(p_buffer, p_frames*sizeof(AudioFrame));
	lock->lock();
	oaml->MixToBuffer(p_buffer, p_frames*2);
	lock->unlock();

	return true;
}

// Called from audio thread
void oamlGodotModule::_mix_audio() {

	AudioFrame *buffer = mix_buffer.ptrw();
	int buffer_size = mix_buffer.size();

	if (!mix(buffer, buffer_size))
		return;

	AudioFrame *target = AudioServer::get_singleton()->thread_get_channel_mix_buffer(0, 0);

	for (int j = 0; j < buffer_size; j++) {
		target[j] += buffer[j];
	}
}

int oamlGodotModule::sp_get_channel_count() const {

	return 2;
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

	lock->lock();
	oaml->LoadTrack(name.ascii());
	lock->unlock();
}

float oamlGodotModule::LoadTrackProgress(String name) {
	if (oaml == NULL)
		return -1.f;

	lock->lock();
	float ret = oaml->LoadTrackProgress(name.ascii());
	lock->unlock();
	return ret;
}

void oamlGodotModule::Pause() {
	if (oaml == NULL)
		return;

	lock->lock();
	oaml->Pause();
	lock->unlock();
}

void oamlGodotModule::PlayTrack(String name) {
	if (oaml == NULL)
		return;

	lock->lock();
	oaml->PlayTrack(name.ascii());
	lock->unlock();
}

void oamlGodotModule::PlayTrackWithStringRandom(String str) {
	if (oaml == NULL)
		return;

	lock->lock();
	oaml->PlayTrackWithStringRandom(str.ascii());
	lock->unlock();
}

void oamlGodotModule::PlayTrackByGroupRandom(String group) {
	if (oaml == NULL)
		return;

	lock->lock();
	oaml->PlayTrackByGroupRandom(group.ascii());
	lock->unlock();
}

void oamlGodotModule::PlayTrackByGroupAndSubgroupRandom(String group, String subgroup) {
	if (oaml == NULL)
		return;

	lock->lock();
	oaml->PlayTrackByGroupAndSubgroupRandom(group.ascii(), subgroup.ascii());
	lock->unlock();
}

void oamlGodotModule::Resume() {
	if (oaml == NULL)
		return;

	lock->lock();
	oaml->Resume();
	lock->unlock();
}

void oamlGodotModule::SetMainLoopCondition(int value) {
	if (oaml == NULL)
		return;

	lock->lock();
	oaml->SetMainLoopCondition(value);
	lock->unlock();
}

void oamlGodotModule::SetCondition(int id, int value) {
	if (oaml == NULL)
		return;

	lock->lock();
	oaml->SetCondition(id, value);
	lock->unlock();
}

void oamlGodotModule::SetLayerGain(String layer, float gain) {
	if (oaml == NULL)
		return;

	lock->lock();
	oaml->SetLayerGain(layer.ascii(), gain);
	lock->unlock();
}

void oamlGodotModule::SetLayerRandomChance(String layer, int randomChance) {
	if (oaml == NULL)
		return;

	lock->lock();
	oaml->SetLayerRandomChance(layer.ascii(), randomChance);
	lock->unlock();
}

void oamlGodotModule::SetTension(int value) {
	if (oaml == NULL)
		return;

	lock->lock();
	oaml->SetTension(value);
	lock->unlock();
}

void oamlGodotModule::SetVolume(float value) {
	if (oaml == NULL)
		return;

	lock->lock();
	oaml->SetVolume(value);
	lock->unlock();
}

void oamlGodotModule::StopPlaying() {
	if (oaml == NULL)
		return;

	lock->lock();
	oaml->StopPlaying();
	lock->unlock();
}

void oamlGodotModule::_bind_methods() {
	ClassDB::bind_method("AddTension", &oamlGodotModule::AddTension);
	ClassDB::bind_method("EnableDynamicCompressor", &oamlGodotModule::EnableDynamicCompressor);
	ClassDB::bind_method("GetPlayingInfo", &oamlGodotModule::GetPlayingInfo);
	ClassDB::bind_method("GetVolume", &oamlGodotModule::GetVolume);
	ClassDB::bind_method("Init", &oamlGodotModule::Init);
	ClassDB::bind_method("InitString", &oamlGodotModule::InitString);
	ClassDB::bind_method("IsPaused", &oamlGodotModule::IsPaused);
	ClassDB::bind_method("IsPlaying", &oamlGodotModule::IsPlaying);
	ClassDB::bind_method("IsTrackPlaying", &oamlGodotModule::IsTrackPlaying);
	ClassDB::bind_method("LoadTrack", &oamlGodotModule::LoadTrack);
	ClassDB::bind_method("LoadTrackProgress", &oamlGodotModule::LoadTrackProgress);
	ClassDB::bind_method("Pause", &oamlGodotModule::Pause);
	ClassDB::bind_method("PlayTrack", &oamlGodotModule::PlayTrack);
	ClassDB::bind_method("PlayTrackWithStringRandom", &oamlGodotModule::PlayTrackWithStringRandom);
	ClassDB::bind_method("PlayTrackByGroupRandom", &oamlGodotModule::PlayTrackByGroupRandom);
	ClassDB::bind_method("PlayTrackByGroupAndSubgroupRandom", &oamlGodotModule::PlayTrackByGroupAndSubgroupRandom);
	ClassDB::bind_method("Resume", &oamlGodotModule::Resume);
	ClassDB::bind_method("SetMainLoopCondition", &oamlGodotModule::SetMainLoopCondition);
	ClassDB::bind_method("SetCondition", &oamlGodotModule::SetCondition);
	ClassDB::bind_method("SetLayerGain", &oamlGodotModule::SetLayerGain);
	ClassDB::bind_method("SetLayerRandomChance", &oamlGodotModule::SetLayerRandomChance);
	ClassDB::bind_method("SetTension", &oamlGodotModule::SetTension);
	ClassDB::bind_method("SetVolume", &oamlGodotModule::SetVolume);
	ClassDB::bind_method("StopPlaying", &oamlGodotModule::StopPlaying);
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
		f->seek(f->get_position()+offset);
	return 0;
}

static long oamlTell(void *fd) {
	FileAccess *f = (FileAccess*)fd;
	return f->get_position();
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
	lock = Mutex::create();

	oaml = new oamlApi();
	oaml->SetFileCallbacks(&fileCbs);
	oaml->SetAudioFormat(AudioServer::get_singleton()->get_mix_rate(), 2, 4, true);

	AudioServer::get_singleton()->lock();
	mix_buffer.resize(AudioServer::get_singleton()->thread_get_mix_buffer_size());
	AudioServer::get_singleton()->unlock();

	AudioServer::get_singleton()->add_callback(_mix_audios, this);
}

oamlGodotModule::~oamlGodotModule() {
	if (oaml != NULL) {
		oaml->Shutdown();
		delete oaml;
		oaml = NULL;
	}

	if (lock != NULL) {
		memdelete(lock);
		lock = NULL;
	}

	AudioServer::get_singleton()->remove_callback(_mix_audios, this);
}


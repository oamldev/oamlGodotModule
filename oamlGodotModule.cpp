#include "core/io/config_file.h"
#include "core/os/file_access.h"

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
	oaml->MixToBuffer(p_buffer, p_frames*2);

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

void oamlGodotModule::ClearConditions() {
	if (oaml == NULL)
		return;

	oaml->ClearConditions();
}

void oamlGodotModule::EnableDynamicCompressor(bool enable, double thresholdDb, double ratio) {
	if (oaml == NULL)
		return;

	oaml->EnableDynamicCompressor(enable, thresholdDb, ratio);
}

float oamlGodotModule::GetLayerGain(String layer) {
	if (oaml == NULL)
		return 0.f;

	return oaml->GetLayerGain(layer.utf8().get_data());
}

int oamlGodotModule::GetLayerRandomChance(String layer) {
	if (oaml == NULL)
		return 0;

	return oaml->GetLayerRandomChance(layer.utf8().get_data());
}

String oamlGodotModule::GetPlayingInfo() {
	if (oaml == NULL)
		return "";

	return String(oaml->GetPlayingInfo());
}

int oamlGodotModule::GetTension() {
	if (oaml == NULL)
		return 0;

	return oaml->GetTension();
}

String oamlGodotModule::GetVersion() {
	if (oaml == NULL)
		return "";

	return oaml->GetVersion();
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

float oamlGodotModule::LoadTrackProgress(String name) {
	if (oaml == NULL)
		return -1.f;

	return oaml->LoadTrackProgress(name.ascii());
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

String oamlGodotModule::SaveState() {
	if (oaml == NULL)
		return "";

	return oaml->SaveState().c_str();
}

void oamlGodotModule::LoadState(String state) {
	if (oaml == NULL)
		return;

	oaml->LoadState(state.utf8().get_data());
}

void oamlGodotModule::_bind_methods() {
	ClassDB::bind_method(D_METHOD("add_tension", "value"), &oamlGodotModule::AddTension);
	ClassDB::bind_method(D_METHOD("clear_conditions"), &oamlGodotModule::ClearConditions);
	ClassDB::bind_method(D_METHOD("enable_dynamic_compressor", "enable", "thresholdDb", "ratio"), &oamlGodotModule::EnableDynamicCompressor, true, -3.0, 4.0);
	ClassDB::bind_method(D_METHOD("get_layer_gain", "layer"), &oamlGodotModule::GetLayerGain);
	ClassDB::bind_method(D_METHOD("get_layer_random_chance", "layer"), &oamlGodotModule::GetLayerRandomChance);
	ClassDB::bind_method(D_METHOD("get_playing_info"), &oamlGodotModule::GetPlayingInfo);
	ClassDB::bind_method(D_METHOD("get_tension"), &oamlGodotModule::GetTension);
	ClassDB::bind_method(D_METHOD("get_version"), &oamlGodotModule::GetVersion);
	ClassDB::bind_method(D_METHOD("get_volume"), &oamlGodotModule::GetVolume);
	ClassDB::bind_method(D_METHOD("init", "defsFilename"), &oamlGodotModule::Init);
	ClassDB::bind_method(D_METHOD("init_string", "defs"), &oamlGodotModule::InitString);
	ClassDB::bind_method(D_METHOD("is_paused"), &oamlGodotModule::IsPaused);
	ClassDB::bind_method(D_METHOD("is_playing"), &oamlGodotModule::IsPlaying);
	ClassDB::bind_method(D_METHOD("is_track_playing", "name"), &oamlGodotModule::IsTrackPlaying);
	ClassDB::bind_method(D_METHOD("load_state", "state"), &oamlGodotModule::LoadState);
	ClassDB::bind_method(D_METHOD("load_track", "name"), &oamlGodotModule::LoadTrack);
	ClassDB::bind_method(D_METHOD("load_track_progress", "name"), &oamlGodotModule::LoadTrackProgress);
	ClassDB::bind_method(D_METHOD("pause"), &oamlGodotModule::Pause);
	ClassDB::bind_method(D_METHOD("play_track", "name"), &oamlGodotModule::PlayTrack);
	ClassDB::bind_method(D_METHOD("play_track_with_string_random", "str"), &oamlGodotModule::PlayTrackWithStringRandom);
	ClassDB::bind_method(D_METHOD("play_track_by_group_random", "group"), &oamlGodotModule::PlayTrackByGroupRandom);
	ClassDB::bind_method(D_METHOD("play_track_by_group_and_subgroup_random", "group", "subgroup"), &oamlGodotModule::PlayTrackByGroupAndSubgroupRandom);
	ClassDB::bind_method(D_METHOD("resume"), &oamlGodotModule::Resume);
	ClassDB::bind_method(D_METHOD("save_state"), &oamlGodotModule::SaveState);
	ClassDB::bind_method(D_METHOD("set_main_loop_condition", "value"), &oamlGodotModule::SetMainLoopCondition);
	ClassDB::bind_method(D_METHOD("set_condition", "id", "value"), &oamlGodotModule::SetCondition);
	ClassDB::bind_method(D_METHOD("set_layer_gain", "layer", "gain"), &oamlGodotModule::SetLayerGain);
	ClassDB::bind_method(D_METHOD("set_layer_random_chance", "layer", "randomChance"), &oamlGodotModule::SetLayerRandomChance);
	ClassDB::bind_method(D_METHOD("set_tension", "value"), &oamlGodotModule::SetTension);
	ClassDB::bind_method(D_METHOD("set_volume", "vol"), &oamlGodotModule::SetVolume);
	ClassDB::bind_method(D_METHOD("stop_playing"), &oamlGodotModule::StopPlaying);
}

static void* oamlOpen(const char *filename) {
	String path = "res://"+String(filename);
	FileAccess *f = FileAccess::open(path, FileAccess::READ);
	if (f == NULL) {
		ConfigFile cf;
		Error err = cf.load(path + ".import");
		if (err == OK) {
			f = FileAccess::open(cf.get_value("remap", "path"), FileAccess::READ);
			if (f != NULL) {
				char header[5] = "0000";
				f->seek(28);
				while (strncmp(header, "OggS", 4) != 0) {
					f->get_buffer((uint8_t*)header, 4);
					f->seek(f->get_position()-3);
				}
				f->seek(f->get_position()-1);
				return (void*)f;
			}
		}

		print_line("oaml: Error opening resource file:" + path);
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

	AudioServer::get_singleton()->remove_callback(_mix_audios, this);
}

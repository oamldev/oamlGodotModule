#ifndef __OAML_GODOT_MODULE_H__
#define __OAML_GODOT_MODULE_H__

#include "servers/audio_server.h"
#include "servers/audio/audio_stream.h"
#include "oaml.h"
#include "core/reference.h"


class oamlGodotModule : public Reference {
	GDCLASS(oamlGodotModule, Reference)

	int sp_get_channel_count() const;
	bool mix(AudioFrame *p_buffer, int p_frames);

	void _mix_audio();
	static void _mix_audios(void *self) { reinterpret_cast<oamlGodotModule *>(self)->_mix_audio(); }

protected:

	Vector<AudioFrame> mix_buffer;
	Mutex *lock;
	RID streamRid;
	oamlApi *oaml;

	void set_mix_rate(int p_rate);

	static void _bind_methods();

public:
	oamlGodotModule();
	~oamlGodotModule();

	void AddTension(int value);
	void ClearConditions();
	void EnableDynamicCompressor(bool enable = true, double thresholdDb = -3.0, double ratio = 4.0);
	float GetLayerGain(String layer);
	int GetLayerRandomChance(String layer);
	String GetPlayingInfo();
	int GetTension();
	String GetVersion();
	float GetVolume();
	void Init(String defsFilename);
	void InitString(String defs);
	bool IsPaused();
	bool IsPlaying();
	bool IsTrackPlaying(String name);
	void LoadState(String state);
	void LoadTrack(String name);
	float LoadTrackProgress(String name);
	void Pause();
	void PlayTrack(String name);
	void PlayTrackWithStringRandom(String str);
	void PlayTrackByGroupRandom(String group);
	void PlayTrackByGroupAndSubgroupRandom(String group, String subgroup);
	void Resume();
	void SetMainLoopCondition(int value);
	void SetCondition(int id, int value);
	void SetLayerGain(String layer, float gain);
	void SetLayerRandomChance(String layer, int randomChance);
	void SetTension(int value);
	void SetVolume(float vol);
	void StopPlaying();
	String SaveState();
};

#endif

#ifndef __OAML_GODOT_MODULE_H__
#define __OAML_GODOT_MODULE_H__

#include "servers/audio_server.h"
#include "oaml.h"
#include "reference.h"



class oamlGodotModule : public Reference {
	OBJ_TYPE(oamlGodotModule, Reference);

protected:
	struct InternalStream : public AudioServer::AudioStream {
		oamlGodotModule *owner;
		virtual int get_channel_count() const;
		virtual void set_mix_rate(int p_rate); //notify the stream of the mix rate
		virtual bool mix(int32_t *p_buffer,int p_frames);
		virtual void update();
	};


	InternalStream *stream;
	RID streamRid;
	oamlApi *oaml;

	void set_mix_rate(int p_rate);
	bool mix(int32_t *p_buffer, int p_frames);

	static void _bind_methods();

public:
	oamlGodotModule();
	~oamlGodotModule();

	void AddTension(int value);
	void EnableDynamicCompressor(bool enable = true, double thresholdDb = -3.0, double ratio = 4.0);
	String GetPlayingInfo();
	float GetVolume();
	void Init(String defsFilename);
	void InitString(String defs);
	bool IsPaused();
	bool IsPlaying();
	bool IsTrackPlaying(String name);
	void LoadTrack(String name);
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
};

#endif

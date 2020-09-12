#pragma once
#include <memory>
#include "Define.h"
#include "GameStateBase.h"
#include "Button.h"
#include "Text.h"
#include "SoundManager.h"

class GSSound : public GameStateBase
{
	static shared_ptr<Sprite> m_background;
	static shared_ptr<Button> m_homeButton;
	static shared_ptr<Button> m_musicOn;
	static shared_ptr<Button> m_musicOff;
	static shared_ptr<Button> m_effectOn;
	static shared_ptr<Button> m_effectOff;
	static shared_ptr<Button> m_volumeUp;
	static shared_ptr<Button> m_volumeDown;
	
	std::shared_ptr<Text> m_textVolume = NULL;
	std::shared_ptr<Text> m_textSoundSetting = NULL;
	std::shared_ptr<Text> m_textMusic = NULL;
	std::shared_ptr<Text> m_textEffect = NULL;
	std::shared_ptr<Text> m_Volume = NULL;
	std::shared_ptr<Text> m_texton = NULL;
	std::shared_ptr<Text> m_textoff = NULL;

	static bool m_isMusic ;
	static bool m_isEffect ;

	static void OnClickHomeButton(int x, int y, bool isPressed, void* context);
	static void OnClickMusicOnButton(int x, int y, bool isPressed, void* context);
	static void OnClickMusicOffButton(int x, int y, bool isPressed, void* context);
	static void OnClickEffectOnButton(int x, int y, bool isPressed, void* context);
	static void OnClickEffectOffButton(int x, int y, bool isPressed, void* context);
	static void OnClickVolumeUpButton(int x, int y, bool isPressed, void* context);
	static void OnClickVolumeDownButton(int x, int y, bool isPressed, void* context);

public:
	GSSound();
	~GSSound();

	void Init();
	void Enter();
	void Pause();
	void Resume();
	void Exit();

	void Key(unsigned char key, bool bIsPressed);
	void TouchActionDown(int x, int y);
	void TouchActionMove(int x, int y);
	void TouchActionUp(int x, int y);

	void Update(float dt);
	void Draw();
};



#ifndef SETTINGS_H
#define SETTINGS_H

class Settings
{
	bool home_down;
	bool prior_down;
	bool next_down;
public:
	bool m_bAutohop;
	bool m_bAutostrafe;
	bool m_bOptimize;

	void Init();
	void ToggleSetting(bool& setting);
	bool KeyDown(int key, bool& keydown);
	void InputListener();
};

extern Settings settings;

#endif

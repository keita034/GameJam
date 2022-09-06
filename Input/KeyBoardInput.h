#pragma once
class KeyBoardInput
{
private:
	char keys[256];
	char oldkeys[256];
public:
	void Update();
	bool GetKey(char key);
	bool GetKeyTrigger(char key);
	bool GetKeyReleased(char key);
	int GetHorizontal(char leftKey, char righKey);
	int GetVertical(char downKey, char upkey);
};
extern KeyBoardInput key;
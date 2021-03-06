#pragma once

#include <dinput.h>
#include <XInput.h>
#include <mutex>



class Input
{
private:

	IDirectInput8*			m_pDirectInput;
	IDirectInputDevice8*	m_pMouseDevice;
	IDirectInputDevice8*	m_pKeyboardDevice;
	DIMOUSESTATE			m_MouseState, m_LastMouseState;

	//IDirectInputDevice8*	m_pControllerDevice;
	XINPUT_STATE			m_ControllerState;
	XINPUT_VIBRATION		m_VibrationState;


	unsigned char			m_KeyboardKeyState[256];
	//int						m_LastMouseX, m_LastMouseY;

	std::mutex Mutex1;

public:


	Input();
	~Input();

	HRESULT InitialiseInput(HINSTANCE hInst, HWND hWnd);
	void ReadInputStates();
	bool IsKeyPressed(unsigned char DI_KEYCODE);
	bool IsButtonPressed(unsigned short BUTTON_CODE);
	bool HasMouseMoved();
	void UpdateMouse();

	float GetMouseX();

	//Controller methods
	float GetControllerLeftAnalogueX();
	float GetControllerLeftAnalogueY();
	float GetControllerRightAnalogueX();
	float GetLeftStickDirection();
	void  SetControllerVibration(float left, float right, float seconds);
};

